import java.util.ArrayList;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Score {
  String name;
  int kor, eng, mat;
  int sum;
  double avg;

  public Score(String name, int kor, int eng, int mat) {
    this.name = name;
    this.kor = kor;
    this.eng = eng;
    this.mat = mat;
    this.sum = kor + eng + mat;
    this.avg = this.sum / 3.0;
  }

  public String toString() {
    return "Name: " + name + ", Total Score: " + sum + ", Average Score: " + String.format("%.2f", avg);
  }
}

class ScoreManager {
  ArrayList<Score> scores = new ArrayList<>();

  public void addScore(Score score) {
    scores.add(score);
  }

  public void printSubjectStats() {
    int sumKor = 0, sumEng = 0, sumMat = 0;
    for (Score score : scores) {
      sumKor += score.kor;
      sumEng += score.eng;
      sumMat += score.mat;
    }
    double avgKor = sumKor / (double) scores.size();
    double avgEng = sumEng / (double) scores.size();
    double avgMat = sumMat / (double) scores.size();

    System.out.println("Subject Stats:");
    System.out.println("Korean - Total: " + sumKor + ", Average: " + String.format("%.2f", avgKor));
    System.out.println("English - Total: " + sumEng + ", Average: " + String.format("%.2f", avgEng));
    System.out.println("Math - Total: " + sumMat + ", Average: " + String.format("%.2f", avgMat));
  }

  public void printStudentStats() {
    System.out.println("Student Stats:");
    for (Score score : scores) {
      System.out.println(score.toString());
    }
  }

  public void printHighestAverage() {
    double maxAvg = -1;
    String name = "";
    for (Score score : scores) {
      if (score.avg > maxAvg) {
        maxAvg = score.avg;
        name = score.name;
      }
    }
    System.out.println("Student with the highest average score: " + name + " - " + String.format("%.2f", maxAvg));
  }
}

public class J083 {

  public static void main(String[] args) {
    ScoreManager manager = new ScoreManager();
    try {
      File file = new File("/Users/jaeho/Documents/LJH/9weeks/resources/data_sub_score.txt");
      Scanner scanner = new Scanner(file);

      while (scanner.hasNext()) {
        String name = scanner.next();
        int kor = scanner.nextInt();
        int eng = scanner.nextInt();
        int mat = scanner.nextInt();

        Score score = new Score(name, kor, eng, mat);
        manager.addScore(score);
      }

      scanner.close();
    } catch (FileNotFoundException e) {
      System.out.println("File not found.");
    }

    manager.printSubjectStats();
    manager.printStudentStats();
    manager.printHighestAverage();
  }
}