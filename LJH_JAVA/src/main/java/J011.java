import java.util.Scanner;

public class J011 {
  public static void main(String[] args) {
    J011 pStudio = new J011();
    pStudio.solveJ011(); // 실행할 문제 번호의 method 실행
  }

  void solveJ011() {
    Scanner scanner = new Scanner(System.in);

    System.out.println("Enter your height in cm:");
    int height = scanner.nextInt();

    System.out.println("Enter your weight in kg:");
    int weight = scanner.nextInt();

    double bmi = weight / Math.pow(height / 100.0, 2);

    String result = bmi >= 25 ? "Yes" : "No";
    System.out.println("Are you obese? " + result);

    scanner.close();
  }
}