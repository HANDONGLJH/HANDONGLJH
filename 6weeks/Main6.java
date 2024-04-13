import java.util.Scanner;

public class Main6 {
  // Move the scanner to be a static class-level variable
  static Scanner scanner = new Scanner(System.in);

  public static void main(String[] args) {
    Main6 pStudio = new Main6();
    while (true) {
      System.out.println("실행하고 싶은 문제 번호를 입력하세요. 종료하려면 -1을 입력하세요.");
      int problemNumber = scanner.nextInt();
      scanner.nextLine(); // Add this line to consume the newline character
      if (problemNumber == -1) {
        System.out.println("프로그램을 종료합니다.");
        scanner.close();
        break;
      }

      // 입력받은 번호에 따라 해당 문제 실행
      switch (problemNumber) {
        case 31:
          pStudio.solveJ031();
          break;
        case 32:
          pStudio.solveJ032();
          break;
        case 33:
          pStudio.solveJ033();
          break;
        case 34:
          pStudio.solveJ034();
          break;
        case 35:
          pStudio.solveJ035();
          break;
        case 36:
          pStudio.solveJ036();
          break;
        case 37:
          pStudio.solveJ037();
          break;
        case 41:
          pStudio.solveJ041();
          break;
        case 42:
          pStudio.solveJ042();
          break;
        case 43:
          pStudio.solveJ043();
          break;
        case 44:
          pStudio.solveJ044();
          break;
        case 45:
          pStudio.solveJ045();
          break;

        default:
          System.out.println("해당 번호의 문제는 존재하지 않습니다.");
      }
    }
    scanner.close();
  }

  void solveJ031() {
    String userId;
    String password;
    String name;

    System.out.print("Enter user ID: ");
    userId = scanner.nextLine();

    System.out.print("Enter password: ");
    password = scanner.nextLine();
    if (password.length() < 3) {
      System.out.println("Error! password is too short.");
      return;
    }

    System.out.print("Enter name: ");
    name = scanner.nextLine();

    System.out.println("User ID: " + userId);
    System.out.println("Password: " + password.substring(0, 2) + "*".repeat(password.length() - 2));
    System.out.println("Name: " + name);
  }

  void solveJ032() {

    System.out.print("Enter a string: ");
    String str = scanner.nextLine();

    StringBuilder reversed = new StringBuilder();
    for (int i = str.length() - 1; i >= 0; i--) {
      reversed.append(str.charAt(i));
    }

    System.out.println("Reversed string: " + reversed.toString());
  }

  void solveJ033() {
    int count;
    String name;
    String longest = "";
    String shortest = "";

    System.out.print("Enter the number of departments: ");
    count = scanner.nextInt();

    longest = "";
    shortest = "zzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for (int i = 0; i < count; i++) {
      System.out.print("Enter department name: ");
      name = scanner.next();
      if (name.length() > longest.length()) {
        longest = name;
      }
      if (name.length() < shortest.length()) {
        shortest = name;
      }
    }

    System.out.println("Longest department name: " + longest);
    System.out.println("Shortest department name: " + shortest);
  }

  void solveJ034() {
    String[] usernames = { "kim", "lee", "park", "hong", "choi" };
    String[] passwords = { "1111", "1234", "3456", "3535", "7777" };

    System.out.print("Enter ID: ");
    String id = scanner.nextLine();

    System.out.print("Enter password: ");
    String password = scanner.nextLine();

    boolean userFound = false;
    int index = -1;

    for (int i = 0; i < usernames.length; i++) {
      if (usernames[i].equals(id)) {
        userFound = true;
        index = i;
        break;
      }
    }

    if (userFound) {
      if (passwords[index].equals(password)) {
        System.out.println("Login OK!");
      } else {
        System.out.println("Incorrect password!");
      }
    } else {
      System.out.println("No user!");
    }
  }

  void solveJ035() {
    String birthdate;
    int year;
    int month;
    int day;
    int sum = 0;

    System.out.print("Enter an 8-digit birthdate (YYYYMMDD): ");
    birthdate = scanner.nextLine();

    year = Integer.parseInt(birthdate.substring(0, 4));
    month = Integer.parseInt(birthdate.substring(4, 6));
    day = Integer.parseInt(birthdate.substring(6));

    sum = year + month + day;

    System.out.println("Birthdate number: " + sum);
  }

  void solveJ036() {

    System.out.print("Enter a sentence: ");
    String sentence = scanner.nextLine().toLowerCase().replaceAll("[^a-z]", "");

    String reversed = new StringBuilder(sentence).reverse().toString();

    if (sentence.equals(reversed)) {
      System.out.println("The sentence is a palindrome.");
    } else {
      System.out.println("The sentence is not a palindrome.");
    }
  }

  void solveJ037() {
    System.out.print("Enter first string: ");
    String s1 = scanner.nextLine().replaceAll("[^a-z]", "");
    System.out.print("Enter second string: ");
    String s2 = scanner.nextLine().replaceAll("[^a-z]", "");
    // isAnagram 로직을 여기에 직접 구현
    if (s1.length() != s2.length()) {
      System.out.println("The strings are not anagrams.");
      return;
    }
    int[] letterCounts = new int[26];
    for (char c : s1.toCharArray()) {
      letterCounts[c - 'a']++;
    }
    for (char c : s2.toCharArray()) {
      if (--letterCounts[c - 'a'] < 0) {
        System.out.println("The strings are not anagrams.");
        return;
      }
    }
    System.out.println("The strings are anagrams.");
  }

  void solveJ041() {
    Lotto lotto = new Lotto();
    lotto.printNumbers();
  }

  void solveJ042() {
    Lotto lotto = new Lotto();
    System.out.println("초기 생성된 로또 번호:");
    lotto.printNumbers();
    lotto.remake();
    System.out.println("새로 입력받은 로또 번호:");
    lotto.printNumbers();
  }

  void solveJ043() {
    Lotto lotto = new Lotto();
    System.out.println("초기 생성된 로또 번호:");
    lotto.printNumbers();
    lotto.remake();
    System.out.println("새로 입력받은 로또 번호:");
    lotto.printNumbers();
    System.out.println("금주의 로또 번호 6개를 입력하세요:");
    int[] checkNumbers = new int[6];
    for (int i = 0; i < 6; i++) {
      checkNumbers[i] = scanner.nextInt();
    }
    int matchCount = lotto.checkLotto(checkNumbers);
    System.out.println("일치하는 번호의 개수: " + matchCount);
  }

  void solveJ044() {
    System.out.print("원하는 암호의 길이를 입력하세요: ");
    int length = scanner.nextInt();
    MakePW makePW = new MakePW();
    makePW.make(length);
  }

  void solveJ045() {
    System.out.print("알파벳 대문자 길이를 입력하세요: ");
    int length1 = scanner.nextInt();
    System.out.print("숫자 길이를 입력하세요: ");
    int length2 = scanner.nextInt();
    // MakePW 객체 생성 및 makeCode 메소드 호출
    MakePW makePW = new MakePW();
    makePW.makeCode(length1, length2);
  }

}