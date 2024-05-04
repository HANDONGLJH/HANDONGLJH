
import java.util.Scanner;

public class Main {
  // Move the scanner to be a static class-level variable
  static Scanner scanner = new Scanner(System.in);

  public static void main(String[] args) {

    while (true) {
      System.out.println("실행하고 싶은 문제 번호를 입력하세요. 종료하려면 -1을 입력하세요.");
      int problemNumber = scanner.nextInt();
      scanner.nextLine(); // Add this line to consume the newline character
      if (problemNumber == -1) {
        System.out.println("프로그램을 종료합니다.");
        scanner.close();
        break;
      }

      // 입력받은 번호에 따라 해당 문제 실행
      switch (problemNumber) {

        case 81:
          J081.main(args);
          break;
        case 82:
          J082.main(args);
          break;
        case 83:
          J083.main(args);
          break;
        case 84:
          J084.main(args);
          break;
        case 85:
          J085.main(args);
          break;
        case 91:
          J091.main(args);
          break;

        default:
          System.out.println("해당 번호의 문제는 존재하지 않습니다.");
      }
    }
    scanner.close();
  }

}