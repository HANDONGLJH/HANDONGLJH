import java.util.HashMap;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Score_HM {
  String name;
  int kor;
  int eng;
  int mat;

  public Score_HM(String name, int kor, int eng, int mat) {
    this.name = name;
    this.kor = kor;
    this.eng = eng;
    this.mat = mat;

  }

  @Override
  public String toString() {
    return "국어: " + kor + ", 영어: " + eng + ", 수학: " + mat;
  }
}

public class J091 {

  public static void main(String[] args) {
    HashMap<String, Score> scoreMap = new HashMap<>();

    try {
      File file = new File("/Users/jaeho/Documents/LJH/9weeks/resources/data_sub_score.txt");
      Scanner scanner = new Scanner(file);

      while (scanner.hasNext()) {
        String name = scanner.next();
        int kor = scanner.nextInt();
        int eng = scanner.nextInt();
        int mat = scanner.nextInt();

        Score score = new Score(name, kor, eng, mat);
        scoreMap.put(name, score);
      }

      scanner.close();
    } catch (FileNotFoundException e) {
      System.out.println("File not found.");
      return;
    }

    Scanner inputScanner = new Scanner(System.in);

    while (true) {
      System.out.println("1. 점수 통계 출력, 2. 학생 검색, 3. 학생 점수 수정, 4. 프로그램 종료");
      int choice = inputScanner.nextInt();
      switch (choice) {
        case 1:
          printStatistics(scoreMap);
          break;
        case 2:
          searchStudent(inputScanner, scoreMap);
          break;
        case 3:
          modifyScores(inputScanner, scoreMap);
          break;
        case 4:
          System.out.println("프로그램을 종료합니다.");
          inputScanner.close();
          return; // 프로그램 종료
        default:
          System.out.println("잘못된 선택입니다. 다시 입력해주세요.");
      }
    }
  }

  public static void printStatistics(HashMap<String, Score> scoreMap) {
    int totalKor = 0, totalEng = 0, totalMat = 0;
    for (Score score : scoreMap.values()) {
      System.out.println(score.name + ": " + score);
      totalKor += score.kor;
      totalEng += score.eng;
      totalMat += score.mat;
    }
    int studentsCount = scoreMap.size();
    System.out.println("국어 평균 점수: " + (studentsCount > 0 ? totalKor / studentsCount : 0));
    System.out.println("영어 평균 점수: " + (studentsCount > 0 ? totalEng / studentsCount : 0));
    System.out.println("수학 평균 점수: " + (studentsCount > 0 ? totalMat / studentsCount : 0));
  }

  public static void searchStudent(Scanner inputScanner, HashMap<String, Score> scoreMap) {
    System.out.println("검색할 학생의 이름을 입력하세요:");
    String name = inputScanner.next();
    if (scoreMap.containsKey(name)) {
      System.out.println(name + "의 점수: " + scoreMap.get(name));
    } else {
      System.out.println("학생을 찾을 수 없습니다.");
    }
  }

  public static void modifyScores(Scanner inputScanner, HashMap<String, Score> scoreMap) {
    System.out.println("점수를 수정할 학생의 이름을 입력하세요:");
    String name = inputScanner.next();
    if (scoreMap.containsKey(name)) {
      System.out.println("새 국어 점수:");
      int kor = inputScanner.nextInt();
      System.out.println("새 영어 점수:");
      int eng = inputScanner.nextInt();
      System.out.println("새 수학 점수:");
      int mat = inputScanner.nextInt();
      scoreMap.put(name, new Score(name, kor, eng, mat));
      System.out.println(name + "의 점수가 수정되었습니다.");
    } else {
      System.out.println("학생을 찾을 수 없습니다.");
    }
  }
}