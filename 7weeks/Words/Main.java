import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    WordCRUD wordCRUD = new WordCRUD(scanner);

    boolean isRunning = true;

    while (isRunning) {
      System.out.println("===== Word Manager =====");
      System.out.println("1. Add Word");
      System.out.println("2. List All Words");
      System.out.println("3. Edit Word");
      System.out.println("4. Delete Word");
      System.out.println("5. Exit");
      System.out.print("Choose an option: ");

      int choice = scanner.nextInt();

      switch (choice) {
        case 1:
          wordCRUD.addWord();
          break;
        case 2:
          wordCRUD.listWords();
          break;
        case 3:
          wordCRUD.updateWord();
          break;
        case 4:
          wordCRUD.deleteWord();
          break;
        case 5:
          System.out.println("Exiting program...");
          isRunning = false;
          break;
        default:
          System.out.println("Invalid option. Please choose again.");
      }
    }

    scanner.close();
  }
}