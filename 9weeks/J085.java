import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class J085 {

  public static int countUpperCase(String line) {
    int count = 0;
    for (char c : line.toCharArray()) {
      if (Character.isUpperCase(c)) {
        count++;
      }
    }
    return count;
  }

  public static int countLowerCase(String line) {
    int count = 0;
    for (char c : line.toCharArray()) {
      if (Character.isLowerCase(c)) {
        count++;
      }
    }
    return count;
  }

  public static int countWhiteSpace(String line) {
    int count = 0;
    for (char c : line.toCharArray()) {
      if (Character.isWhitespace(c)) {
        count++;
      }
    }
    return count;
  }

  public static void main(String[] args) {
    int totalUpperCase = 0, totalLowerCase = 0, totalWhiteSpace = 0;
    try {
      File file = new File("/Users/jaeho/Documents/LJH/9weeks/resources/school_name.txt");
      Scanner scanner = new Scanner(file);

      int lineNumber = 1;
      while (scanner.hasNextLine()) {
        String line = scanner.nextLine();
        int upperCaseCount = countUpperCase(line);
        int lowerCaseCount = countLowerCase(line);
        int whiteSpaceCount = countWhiteSpace(line);

        totalUpperCase += upperCaseCount;
        totalLowerCase += lowerCaseCount;
        totalWhiteSpace += whiteSpaceCount;

        System.out.println("Line " + lineNumber + " - 대문자 알파벳 수: " + upperCaseCount
          + ", 소문자 수: " + lowerCaseCount + ", 공백 수: " + whiteSpaceCount);

        lineNumber++;
      }

      scanner.close();
    } catch (FileNotFoundException e) {
      System.out.println("File not found.");
    }
    System.out.println("파일 내 모든 대문자 수: " + totalUpperCase
        + ", 모든 소문자 수: " + totalLowerCase + ", 모든 공백 수: " + totalWhiteSpace);
  }
}