import java.util.Scanner;

public class J012 {
  public static void main(String[] args) {
    J012 pStudio = new J012();
    pStudio.solveJ012(); // 실행할 문제 번호의 method 실행
  }

  void solveJ012() {
    Scanner scanner = new Scanner(System.in);

    // Variables for square meter area and pyung area
    double m2_area;
    double pyung_area;

    // Input for square meter area
    System.out.println("Enter the square meter area of the apartment:");
    m2_area = scanner.nextDouble();

    // Calculating pyung area
    pyung_area = m2_area / 3.305;

    // Determining apartment type based on pyung area
    String apt_type;
    if (pyung_area < 15) {
      apt_type = "small";
    } else if (pyung_area < 30) {
      apt_type = "normal";
    } else if (pyung_area < 50) {
      apt_type = "large";
    } else {
      apt_type = "huge";
    }

    // Output the result
    System.out.println("Apartment pyung area: " + pyung_area);
    System.out.println("Apartment type: " + apt_type);

    scanner.close();
  }
}