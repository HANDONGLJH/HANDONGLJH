
import java.util.Scanner;

public class BookMain {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    BookCRUD bookCRUD = new BookCRUD(scanner);

    boolean isRunning = true;

    while (isRunning) {
      System.out.println("===== Book Manager =====");
      System.out.println("1. Add Book");
      System.out.println("2. List All Books");
      System.out.println("3. Edit Book");
      System.out.println("4. Delete Book");
      System.out.println("5. Exit");
      System.out.print("Choose an option: ");

      int choice = scanner.nextInt();
      scanner.nextLine(); // Consume newline left-over

      switch (choice) {
        case 1:
          bookCRUD.addBook();
          break;
        case 2:
          bookCRUD.listBooks();
          break;
        case 3:
          bookCRUD.updateBook();
          break;
        case 4:
          bookCRUD.deleteBook();
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