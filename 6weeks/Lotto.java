import java.util.Random;
import java.util.Scanner;

public class Lotto {
  int[] numbers = new int[6];
  Scanner scanner = new Scanner(System.in);

  public Lotto() {
    this.remakeAuto();
  }

  public void printNumbers() {
    for (int number : numbers) {
      System.out.print(number + " ");
    }
    System.out.println();
  }

  public void remakeAuto() {
    Random random = new Random();
    for (int i = 0; i < numbers.length; i++) {
      numbers[i] = random.nextInt(45) + 1;
      for (int j = 0; j < i; j++) {
        if (numbers[i] == numbers[j]) {
          i--; // If found duplicate, decrement i to replace the number
          break;
        }
      }
    }
  }

  public void remake() {
    System.out.println("새로운 로또 번호 6개를 입력해주세요 (1-45 사이): ");
    for (int i = 0; i < numbers.length;) {
      int newNumber = scanner.nextInt();
      if (newNumber < 1 || newNumber > 45) {
        System.out.println("1-45 사이의 숫자를 입력해주세요.");
        continue;
      }
      boolean isDuplicate = false;
      for (int j = 0; j < i; j++) {
        if (numbers[j] == newNumber) {
          isDuplicate = true;
          break;
        }
      }
      if (!isDuplicate) {
        numbers[i] = newNumber;
        i++;
      } else {
        System.out.println("중복된 번호입니다. 다시 입력해주세요.");
      }
    }
  }

  public int checkLotto(int[] checkNumbers) {
    int matchCount = 0;
    for (int i = 0; i < 6; i++) {
      for (int checkNumber : checkNumbers) {
        if (numbers[i] == checkNumber) {
          matchCount++;
          break;
        }
      }
    }
    return matchCount;
  }
}