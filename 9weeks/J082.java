import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class J082 {

  public static void main(String[] args) {
    try {
      File file = new File("/Users/jaeho/Documents/LJH/9weeks/resources/data_ow.txt");
      Scanner scanner = new Scanner(file);

      int totalPeople = 0;
      int obesePeople = 0;

      while (scanner.hasNext()) {
        int height = scanner.nextInt();
        int weight = scanner.nextInt();

        double bmi = weight / Math.pow(height / 100.0, 2);

        if (bmi >= 26) {
          obesePeople++;
        }

        totalPeople++;
      }

      double obeseRatio = (double) obesePeople / totalPeople * 100;

      System.out.println("Total People: " + totalPeople);
      System.out.println("Obese People: " + obesePeople + " (" + String.format("%.2f", obeseRatio) + "%)");

      scanner.close();
    } catch (FileNotFoundException e) {
      System.out.println("File not found.");
    }
  }
}
