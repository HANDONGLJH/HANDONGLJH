import java.util.Arrays;
import java.util.Scanner;

public class Score {
  int count; // 학생 인원 수
  int[][] jumsu; // 점수를 저장하고 있는 2차원 배열 (학생별, 과목별)
  int[] sum_student; // 학생별 총점
  double[] average_student; // 학생별 평균
  int[] sum_class; // 과목별 총점
  double[] average_class; // 과목별 평균
  static Scanner scanner = new Scanner(System.in);

  public Score(int count) {
    this.count = count;
    this.jumsu = new int[count][3]; // 예를 들어, 학생별 국어, 영어, 수학 점수
    this.sum_student = new int[count];
    this.average_student = new double[count];
    this.sum_class = new int[3];
    this.average_class = new double[3];
  }

  // 점수 입력 및 총점과 평균 계산
  public void getScore() {
    for (int i = 0; i < count; i++) {
      System.out.println((i + 1) + "번 학생의 국어, 영어, 수학 점수를 입력하세요:");
      for (int j = 0; j < 3; j++) {
        jumsu[i][j] = scanner.nextInt();
        sum_student[i] += jumsu[i][j];
        sum_class[j] += jumsu[i][j];
      }
      average_student[i] = sum_student[i] / 3.0;
    }
    for (int i = 0; i < 3; i++) {
      average_class[i] = sum_class[i] / (double) count;
    }
  }

  // 학생들의 점수 출력
  public void printScore() {
    for (int i = 0; i < count; i++) {
      System.out.printf("%d번 학생 - 국어: %d, 영어: %d, 수학: %d, 총점: %d, 평균: %.2f\n",
          i + 1, jumsu[i][0], jumsu[i][1], jumsu[i][2], sum_student[i], average_student[i]);
    }
    // 과목별 평균 점수 출력
    System.out.printf("국어 평균: %.2f, 영어 평균: %.2f, 수학 평균: %.2f\n",
        average_class[0], average_class[1], average_class[2]);
  }

  // num 학생의 점수, 총점, 평균 출력
  public void printScore(int num) {
    int studentIndex = num - 1;
    System.out.printf("%d번 학생 - 국어: %d, 영어: %d, 수학: %d, 총점: %d, 평균: %.2f\n",
        num, jumsu[studentIndex][0], jumsu[studentIndex][1], jumsu[studentIndex][2],
        sum_student[studentIndex], average_student[studentIndex]);
  }

  // num 과목의 총점, 평균 출력
  public void printScore(int num, String classname) {
    System.out.printf("%s 총점: %d, 평균: %.2f\n", classname, sum_class[num - 1], average_class[num - 1]);
  }
}