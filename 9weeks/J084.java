import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class J084 {

  public static void main(String[] args) {
    try {
      File file = new File("/Users/jaeho/Documents/LJH/9weeks/resources/school_name.txt");
      Scanner scanner = new Scanner(file);

      int totalSchools = 0;
      String longestName = "";
      String shortestName = "";

      // Using nextLine() instead of next() to read the entire line
      while (scanner.hasNextLine()) {
        String name = scanner.nextLine();
        totalSchools++;

        if (longestName.equals("") || name.length() > longestName.length()) {
          longestName = name;
        }

        if (shortestName.equals("") || name.length() < shortestName.length()) {
          shortestName = name;
        }
      }

      System.out.println(totalSchools);
      System.out.println(longestName);
      System.out.println(shortestName);

      scanner.close();
    } catch (FileNotFoundException e) {
      System.out.println("File not found.");
    }
  }
}