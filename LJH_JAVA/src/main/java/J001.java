import java.util.Scanner;

public class J001 {
  public static void main(String[] args) {
    J001 pStudio = new J001();
    pStudio.solveJ001(); // 실행할 문제 번호의 method 실행
  }

  void solveJ001() {
    Scanner scanner = new Scanner(System.in);

    // Variables for height (in cm) and weight, and BMI
    int height, weight;
    double bmi;

    // Input for height and weight
    System.out.println("Enter your height in cm:");
    height = scanner.nextInt();
    System.out.println("Enter your weight in kg:");
    weight = scanner.nextInt();

    // Calculating BMI
    bmi = weight / Math.pow(height * 0.01, 2);

    // Output BMI
    System.out.printf("Your BMI is: %.2f", bmi);

    // Close the scanner
    scanner.close();
  }
}