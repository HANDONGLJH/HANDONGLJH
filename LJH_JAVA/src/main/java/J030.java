import java.util.Scanner;

public class J030 {
  public static void main(String[] args) {
    J030 pStudio = new J030();
    pStudio.solveJ030();
  }

  void solveJ030() {

    Scanner scanner = new Scanner(System.in);
    String[] names = { "James", "David", "Simon", "Peter", "Jason" };
    int[][] sheet = new int[5][10];
    int[] answer = { 1, 2, 3, 4, 1, 2, 3, 4, 3, 2 };
    int[] grade = new int[5];

    // Input each student's answers
    for (int i = 0; i < 5; i++) {
      System.out.println("Enter 10 answers for " + names[i] + ":");
      for (int j = 0; j < 10; j++) {
        sheet[i][j] = scanner.nextInt();
      }
    }

    // Grade each student
    for (int i = 0; i < sheet.length; i++) {
      int correctAnswers = 0;
      for (int j = 0; j < sheet[i].length; j++) {
        if (sheet[i][j] == answer[j]) {
          correctAnswers++;
        }
      }
      if (correctAnswers >= 9) {
        grade[i] = 1;
      } else if (correctAnswers >= 7) {
        grade[i] = 2;
      } else {
        grade[i] = 3; // Fail
      }
    }

    // Output results
    int[] countGrade = { 0, 0, 0 };
    for (int i = 0; i < grade.length; i++) {
      if (grade[i] <= 2) {
        System.out.println(names[i] + " is " + (grade[i] == 1 ? "1st" : "2nd"));
        countGrade[grade[i] - 1]++;
      } else {
        System.out.println(names[i] + " is Fail");
        countGrade[2]++;
      }
    }
    System.out.println("1st grade: " + countGrade[0] + " students");
    System.out.println("2nd grade: " + countGrade[1] + " students");
    System.out.println("Fail: " + countGrade[2] + " students");
  }
}