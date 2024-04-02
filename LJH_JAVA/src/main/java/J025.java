import java.util.Scanner;

public class J025 {
  public static void main(String[] args) {
    J025 pStudio = new J025();
    pStudio.solveJ025();
  }

  void solveJ025() {

    Scanner scanner = new Scanner(System.in);
    int[] monthDays = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int month, day;
    int dayCount = 0;

    while (true) {
      System.out.println("Enter month and day:");
      month = scanner.nextInt();
      day = scanner.nextInt();

      if (month < 1 || month > 12 || day < 1 || day > monthDays[month - 1]) {
        System.out.println("Wrong date!");
        continue;
      }

      for (int i = 0; i < month - 1; i++) {
        dayCount += monthDays[i];
      }
      dayCount += day;

      System.out.println("Day number of the year: " + dayCount);
      break;
    }
  }
}