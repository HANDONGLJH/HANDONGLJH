import java.util.Scanner;

public class J002 {
  public static void main(String[] args) {
    J002 pStudio = new J002();
    pStudio.solveJ002(); // 실행할 문제 번호의 method 실행
  }

  void solveJ002() {
    Scanner scanner = new Scanner(System.in);

    // Variables for Celsius and Fahrenheit
    double c_degree, f_degree;

    // Input for Celsius temperature
    System.out.println("Enter the temperature in Celsius:");
    c_degree = scanner.nextDouble();

    // Calculating Fahrenheit temperature
    f_degree = c_degree * 1.8 + 32;

    // Output Fahrenheit temperature
    System.out.printf("The temperature in Fahrenheit is: %.2f", f_degree);

    // Close the scanner
    scanner.close();
  }
}