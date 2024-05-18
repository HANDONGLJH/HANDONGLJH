// SimpleChat Server
import java.net.*;
import java.io.*;
import java.util.*;
import java.text.SimpleDateFormat;

public class ChatServer {
    public static void main(String[] args) {
        try {
            ServerSocket server = new ServerSocket(10001);
            System.out.println("Waiting Connections...");
            HashMap<String, PrintWriter> hm = new HashMap<>();
            HashSet<String> banned = new HashSet<>(); // 등록된 금지단어 목록

            banned.add("Fuck");
   			banned.add("Hell");
      		banned.add("Asshole");

      		
            while (true) {
                Socket sock = server.accept();
                ChatThread chatthread = new ChatThread(sock, hm, banned);
                chatthread.start();
            } // while
        } catch (Exception e) {
            System.out.println(e);
        }
    } // main
}

class ChatThread extends Thread {
    private Socket sock;
    private String id;
    private BufferedReader br;
    private HashMap<String, PrintWriter> hm;
    private HashSet<String> banned; // 금지단어 목록
    private boolean initFlag = false;

    public ChatThread(Socket sock, HashMap<String, PrintWriter> hm, HashSet<String> banned) {
        this.sock = sock;
        this.hm = hm;
        this.banned = banned;
        try {
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(sock.getOutputStream()));
            br = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            id = br.readLine();
            broadcast(id + " entered.");
            System.out.println("[Server log] " + id + " entered.");
            synchronized (hm) {
                hm.put(this.id, pw);
            }
            initFlag = true;
        } catch (Exception ex) {
            System.out.println(ex);
        }
    }
    
    public void run() {
        try {
            String line = null;
            while ((line = br.readLine()) != null) {
                if (line.equals("/quit"))
                    break;
                if (line.indexOf("/to ") == 0) {
                    sendmsg(line);
                } else if (line.indexOf("/ban ") == 0) {
                    addBannedWord(line);
                } else {
                    broadcast(id + " : " + line);
                }
            }
        } catch (Exception ex) {
            System.out.println(ex);
        } finally {
            synchronized (hm) {
                hm.remove(id);
            }
            broadcast(id + " exited.");
            System.out.println("[Server log] " + id + " exited.");
            try {
                if (sock != null)
                    sock.close();
            } catch (Exception ex) {}
        }
    } // run

    private void addBannedWord(String line) {
        String word = line.substring("/ban ".length()).trim();
        synchronized (banned) {
            banned.add(word);
            PrintWriter pw = hm.get(id);
            if (pw != null) {
                pw.println(word + " Added a banned word");
                pw.flush();
            }
        }
    }

    public void sendmsg(String msg) {
        int start = msg.indexOf(" ") + 1;
        int end = msg.indexOf(" ", start);
        if (end != -1) {
            String to = msg.substring(start, end);
            String msg2 = msg.substring(end + 1);
            Object obj = hm.get(to);
            if (obj != null) {
                PrintWriter pw = (PrintWriter) obj;
                pw.println("[" + now() + "]" + id + "'s secret message: " + msg2);
                pw.flush();
            } // if
        }
    } // sendmsg

    public void broadcast(String msg) {
        synchronized (hm) {
            boolean isBanned = false;
            synchronized (banned) {
                for (String word : banned) {
                    if (msg.contains(word)) {
                        isBanned = true;
                        break;
                    }
                }
            }
            if (!isBanned) {
                for (PrintWriter pw : hm.values()) {
                    pw.println("[" + now() + "]" + msg);
                    pw.flush();
                }
            } else {
                PrintWriter pw = hm.get(id);
                if (pw != null) {
                    pw.println("Don't use banned words! ");
                    pw.flush();
                }
            }
        }
    } // broadcast

    private String now() {
        SimpleDateFormat format = new SimpleDateFormat("HH:mm:ss");
        return format.format(new Date());
    }
}