import java.util.Scanner;

public class Main7 {
  // Move the scanner to be a static class-level variable
  static Scanner scanner = new Scanner(System.in);

  public static void main(String[] args) {
    Main7 pStudio = new Main7();
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

        case 46:
          pStudio.solveJ046();
          break;
        case 47:
          pStudio.solveJ047();
          break;
        case 48:
          pStudio.solveJ048();
          break;
        case 51:
          pStudio.solveJ051();
          break;
        case 52:
          pStudio.solveJ052();
          break;
        case 53:
          pStudio.solveJ053();
          break;
        case 54:
          pStudio.solveJ054();
          break;

        default:
          System.out.println("해당 번호의 문제는 존재하지 않습니다.");
      }
    }
    scanner.close();
  }

  void solveJ046() {
    System.out.print("첫 번째 문자열을 입력해주세요: ");
    String str1 = scanner.nextLine();
    System.out.print("두 번째 문자열을 입력해주세요: ");
    String str2 = scanner.nextLine();
    int result = MyString.whichFirst(str1, str2);
    if (result < 0) {
      System.out.println("\"" + str1 + "\"이(가) \"" + str2 + "\"보다 사전적으로 앞섭니다.");
    } else if (result > 0) {
      System.out.println("\"" + str2 + "\"이(가) \"" + str1 + "\"보다 사전적으로 앞섭니다.");
    } else {
      System.out.println("두 문자열이 동일합니다.");
    }
  }

  void solveJ047() {
    System.out.print("문장을 입력해주세요: ");
    String sentence = scanner.nextLine();
    String removedSpaces = MyString.removeSpaces(sentence);
    System.out.println("공백이 제거된 문장: " + removedSpaces);
  }

  void solveJ048() {
    System.out.print("문장을 입력해주세요: ");
    String sentence = scanner.nextLine();
    String longestWord = MyString.findLongestWord(sentence);
    System.out.println("가장 긴 단어: " + longestWord);
    System.out.println("그 길이: " + longestWord.length());
  }

  void solveJ051() {
    System.out.print("원하는 암호의 길이를 입력하세요: ");
    int length = scanner.nextInt();
    System.out.print("생성할 암호의 개수를 입력하세요: ");
    int amount = scanner.nextInt();

    MakePW makePW = new MakePW();
    makePW.make(length, amount);
  }

  void solveJ052() {
    // Score 객체 생성, 여기서는 5명의 학생 점수를 다룰 수 있도록 설정.
    Score score = new Score(5);
    // 5명의 학생의 국, 영, 수 점수를 입력받음
    score.getScore();
    // 입력받은 점수, 총점, 평균, 등급 출력
    score.printScore();
  }

  void solveJ053() {
    Score score = new Score(5);
    score.getScore();
    // 3단계: 특정한 학생의 점수, 총점, 평균 출력
    System.out.print("조회할 학생의 번호를 입력하세요(1~5): ");
    int studentNumber = scanner.nextInt(); // 사용자로부터 조회할 학생 번호 입력받음

    if (studentNumber < 1 || studentNumber > 5) {
      System.out.println("잘못된 학생 번호입니다. 1부터 5 사이의 번호를 입력하세요."); // 에러 메시지 출력
    } else {
      score.printScore(studentNumber); // 입력받은 번호에 해당하는 학생의 점수 정보 출력
    }
  }

  void solveJ054() {
    Score score = new Score(5);
    score.getScore();
    System.out.println("국어 점수");
    score.printScore(1, "국어");
    System.out.println("영어 점수");
    score.printScore(2, "영어");
    System.out.println("수학 점수");
    score.printScore(3, "수학");
  }

}