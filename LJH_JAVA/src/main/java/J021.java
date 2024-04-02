import java.util.Scanner;

public class J021 {
  public static void main(String[] args) {
    J021 pStudio = new J021();
    pStudio.solveJ021();
  }

  void solveJ021() {
    Scanner inputScanner = new Scanner(System.in);
    int people = inputScanner.nextInt();

    int obesePeople = 0;
    while (people-- > 0) {
      int height = inputScanner.nextInt();
      int weight = inputScanner.nextInt();

      // Manual calculation of BMI without using Math.pow
      double heightInMeters = height / 100.0;
      double bmi = weight / (heightInMeters * heightInMeters);

      if (bmi >= 25) {
        obesePeople++;
      }
    }

    System.out.println(obesePeople);
  }
}
