import java.util.*;

public class TodoCRUD implements iCRUD {
  private ArrayList<TodoItem> list;
  private Scanner sc;

  public TodoCRUD(Scanner scanner) {
    this.list = new ArrayList<>();
    this.sc = scanner;
  }

  @Override
  public Object createItem() {
    System.out.print("\nEnter the title of the new Todo item: ");
    String title = sc.nextLine().trim();
    if (isDuplicated(title)) {
      System.out.println("Title can't be duplicated.");
      return null;
    }
    System.out.print("Enter the detail: ");
    String detail = sc.nextLine().trim();
    return new TodoItem(title, detail);
  }

  @Override
  public int addItem() {
    TodoItem t = (TodoItem) createItem();
    if (t != null) {
      this.list.add(t);
      System.out.println("Item added.");
      return 0;
    } else {
      return 1;
    }
  }

  @Override
  public int updateItem() {
    System.out.print("\nEnter the title of the Todo item to update: ");
    String title = sc.nextLine().trim();
    for (TodoItem item : list) {
      if (item.getTitle().equals(title)) {
        System.out.print("Enter new detail: ");
        String newDetail = sc.nextLine().trim();
        item.setDetail(newDetail);
        System.out.println("Todo item updated.");
        return 0;
      }
    }
    System.out.println("Item not found.");
    return 1;
  }

  @Override
  public int deleteItem() {
    System.out.print("\nEnter the title of the Todo item to delete: ");
    String title = sc.nextLine().trim();
    Iterator<TodoItem> iterator = list.iterator();
    while (iterator.hasNext()) {
      TodoItem item = iterator.next();
      if (item.getTitle().equals(title)) {
        iterator.remove();
        System.out.println("Todo item deleted.");
        return 0;
      }
    }
    System.out.println("Item not found.");
    return 1;
  }

  @Override
  public int printItem() {
    if (list.isEmpty()) {
      System.out.println("\nThe list is empty.");
      return 1;
    } else {
      System.out.println("\nTotal " + this.list.size() + " items:");
      for (TodoItem item : this.list) {
        System.out.println(item.toString());
      }
      return 0;
    }
  }

  boolean isDuplicated(String title) {
    for (TodoItem item : this.list) {
      if (title.equals(item.getTitle())) {
        return true;
      }
    }
    return false;
  }

  public void sortByName() {
    Collections.sort(this.list, new TodoitemNameComparator());
  }

  public void sortByDate() {
    Collections.sort(this.list, new TodoitemDateComparator());
  }

  public void reverseList() {
    Collections.reverse(this.list);
  }
}

class TodoitemNameComparator implements Comparator<TodoItem> {
  @Override
  public int compare(TodoItem o1, TodoItem o2) {
    return o1.getTitle().compareTo(o2.getTitle());
  }
}

class TodoitemDateComparator implements Comparator<TodoItem> {
  @Override
  public int compare(TodoItem o1, TodoItem o2) {
    return o1.getReg_date().compareTo(o2.getReg_date());
  }
}
