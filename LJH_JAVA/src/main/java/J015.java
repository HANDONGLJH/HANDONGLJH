import java.util.Scanner;

public class J015 {
  public static void main(String[] args) {
    J015 pStudio = new J015();
    pStudio.solveJ015();
  }

  void solveJ015() {
    int num1, num2, num3;
    int max_num, min_num;

    // Input for three numbers
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter three numbers:");
    num1 = scanner.nextInt();
    num2 = scanner.nextInt();
    num3 = scanner.nextInt();

    // Determine the maximum number without using Math.max
    max_num = num1;
    if (num2 > max_num) {
      max_num = num2;
    }
    if (num3 > max_num) {
      max_num = num3;
    }

    // Determine the minimum number without using Math.min
    min_num = num1;
    if (num2 < min_num) {
      min_num = num2;
    }
    if (num3 < min_num) {
      min_num = num3;
    }

    // Output the maximum and minimum numbers
    System.out.println("Max number: " + max_num);
    System.out.println("Min number: " + min_num);
  }
}