import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class J081 {

  public static void main(String[] args) {
    try {
      File file = new File("/Users/jaeho/Documents/LJH/9weeks/resources/data_Mm.txt");
      Scanner scanner = new Scanner(file);

      int max = Integer.MIN_VALUE;
      int min = Integer.MAX_VALUE;

      while (scanner.hasNextInt()) {
        int num = scanner.nextInt();
        max = Math.max(max, num);
        min = Math.min(min, num);
      }

      System.out.println("Max num: " + max);
      System.out.println("Min num: " + min);

      scanner.close();
    } catch (FileNotFoundException e) {
      System.out.println("File not found.");
    }
  }
}