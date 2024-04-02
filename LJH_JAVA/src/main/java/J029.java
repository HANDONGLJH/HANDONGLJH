import java.util.Scanner;

public class J029 {
  public static void main(String[] args) {
    J029 pStudio = new J029();
    pStudio.solveJ029();
  }

  void solveJ029() {

    Scanner scanner = new Scanner(System.in);
    int[] number = new int[10];
    int count = 0;

    while (count < 10) {
      System.out.println("Enter a number between 1 and 100 (" + (count + 1) + "/10):");
      int input = scanner.nextInt();

      if (input < 1 || input > 100) {
        System.out.println("Number must be between 1 and 100. Retry.");
        continue;
      }

      boolean isDuplicate = false;
      for (int i = 0; i < count; i++) {
        if (number[i] == input) {
          isDuplicate = true;
          break;
        }
      }

      if (isDuplicate) {
        System.out.println("Duplicated! Retry.");
      } else {
        number[count++] = input;
      }
    }

    System.out.println("The numbers are:");
    for (int num : number) {
      System.out.println(num);
    }
  }
}