import java.util.Scanner;

public class J024 {
  public static void main(String[] args) {
    J024 pStudio = new J024();
    pStudio.solveJ024();
  }

  void solveJ024() {
    Scanner inputScanner = new Scanner(System.in); // Initialization of the Scanner object
    int[] numbers = new int[10];
    int first;
    int second;
    int second_max_index = 0;
    // Input 10 integers
    System.out.println("Enter 10 numbers:");
    for (int i = 0; i < 10; i++) {
      numbers[i] = inputScanner.nextInt();
    }

    first = Integer.MIN_VALUE;
    second = Integer.MIN_VALUE;

    for (int i = 0; i < 10; i++) {
      if (numbers[i] > first) {
        second = first;
        first = numbers[i];
      } else if (numbers[i] > second && numbers[i] != first) {
        second = numbers[i];
        second_max_index = i;
      }
    }

    if (second_max_index == -1) {
      System.out.println("A second largest number does not exist.");
    } else {
      System.out.println("The second largest number is at index: " + second_max_index + " with a value of " + second);
    }
  }
}