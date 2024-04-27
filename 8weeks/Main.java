import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    TodoCRUD manager = new TodoCRUD(scanner);
    Main mainInstance = new Main();
    mainInstance.run(manager);
  }

  public void displayHelp() {
    System.out.println("===== Usage of commands =====");
    System.out.println("1. Add a new item ( add )");
    System.out.println("2. Delete an existing item ( del )");
    System.out.println("3. Update an item ( edit ) ");
    System.out.println("4. List all items ( ls )");
    System.out.println("5. sort the list by name ( ls name )");
    System.out.println("6. sort the list by name descending ( ls name desc)");
    System.out.println("7. sort the list by date ( ls date )");
    System.out.println("8. sort the list by date descending ( ls date desc )");
    System.out.println("9. show commands guidelines ( ? )");
    System.out.println("10. quit program ( exit )");
    System.out.print("Choose an option: ");
  }

  public void run(TodoCRUD manager) {
    Scanner sc = new Scanner(System.in);
    boolean quit = false;
    do {
      displayHelp();
      System.out.print("> ");
      String line = sc.nextLine();
      String[] command = line.split(" ");
      String choice = command[0];
      switch (choice) {
        case "add":
          manager.addItem();
          break;
        case "del":
          manager.deleteItem();
          break;
        case "edit":
          manager.updateItem();
          break;
        case "ls":
          if (line.contains("name desc")) {
            manager.sortByName();
            manager.reverseList();
          } else if (line.contains("name")) {
            manager.sortByName();
          } else if (line.contains("date desc")) {
            manager.sortByDate();
            manager.reverseList();
          } else if (line.contains("date")) {
            manager.sortByDate();
          }
          manager.printItem();
          break;
        case "?":
          displayHelp();
          break;
        case "exit":
          quit = true;
          break;
        default:
          System.out.println("? for help.");
          break;
      }
    } while (!quit);
    sc.close();
  }
}