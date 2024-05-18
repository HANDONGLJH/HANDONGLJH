

import java.io.IOException;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Main test2024 = new Main();
    test2024.run();
  }

  public void printMenu() {
    System.out.print("\n[Menu] " +
        "1. Add " +
        "2. Delete " +
        "3. Update " +
        "4. List " +
        "5. Report " +
        "6. Save " +
        "0. Quit > ");
  }

  public void run() {
    Scanner sc = new Scanner(System.in);
    BmiCRUD manager = new BmiCRUD();
    try {
      manager.loadData();
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
    boolean quit = false;
    do {
      printMenu();
      int menu = sc.nextInt();
      sc.nextLine(); 
      switch (menu) {
        case 1:
          manager.addItem();
          break;

        case 2:
          manager.deleteItem();
          break;

        case 3:
          manager.updateItem();
          break;

        case 4:
          System.out.println("Sort by [1]name,[2]bmi? >1 ");
          String line = sc.nextLine();
          if (line.trim().equalsIgnoreCase("name")) {
            manager.sortByName();
          } else if (line.trim().equalsIgnoreCase("bmi")) {
            manager.sortByBmi();
          }
          manager.printAll();
          break;

        case 5:
          manager.report();
          break;

        case 6:
          try {
            manager.saveData();
          } catch (IOException e) {
            e.printStackTrace();
            System.out.println("Failed to save data.");
          }
          break;

        case 0:
          quit = true;
          break;

        default:
          System.out.println("Wrong number.\n");
          break;
      }
    } while (!quit);
  }
}