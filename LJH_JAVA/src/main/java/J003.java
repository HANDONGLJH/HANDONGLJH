import java.util.Scanner;

public class J003 {
  public static void main(String[] args) {
    J003 pStudio = new J003();
    pStudio.solveJ003(); // 실행할 문제 번호의 method 실행
  }

  void solveJ003() {
    Scanner scanner = new Scanner(System.in);

    // Variables for square meters and pyeong
    double m2_area, pyung_area;

    // Input for apartment area in square meters
    System.out.println("Enter the apartment area in square meters:");
    m2_area = scanner.nextDouble();

    // Calculating area in pyeong
    pyung_area = m2_area / 3.305;

    // Output area in pyeong
    System.out.printf("The area in pyeong is: %.2f", pyung_area);

    // Close the scanner
    scanner.close();
  }
}