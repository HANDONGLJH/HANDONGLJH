import java.util.Scanner;

public class J005 {
  public static void main(String[] args) {
    J005 pStudio = new J005();
    pStudio.solveJ005(); // 실행할 문제 번호의 method 실행
  }

  void solveJ005() {
    Scanner scanner = new Scanner(System.in);

    // Variables for month, day, and day count
    int month, day;
    int day_count = 0;

    // Input for month and day
    System.out.println("Enter the month and day:");
    month = scanner.nextInt();
    day = scanner.nextInt();

    // Calculating the day of the year
    switch (month) {
      case 1:
        day_count = 0;
        break;
      case 2:
        day_count = 31;
        break;
      case 3:
        day_count = 59;
        break;
      case 4:
        day_count = 90;
        break;
      case 5:
        day_count = 120;
        break;
      case 6:
        day_count = 151;
        break;
      case 7:
        day_count = 181;
        break;
      case 8:
        day_count = 212;
        break;
      case 9:
        day_count = 243;
        break;
      case 10:
        day_count = 273;
        break;
      case 11:
        day_count = 304;
        break;
      case 12:
        day_count = 334;
        break;
    }
    day_count += day;

    // Output the result
    System.out.printf("It's the %dth day of the year.", day_count);

    scanner.close();
  }
}