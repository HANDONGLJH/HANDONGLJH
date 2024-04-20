import java.util.ArrayList;
import java.util.Scanner;

public class BookCRUD {
  ArrayList<Book> bookList;
  Scanner scanner;

  public BookCRUD(Scanner scanner) {
    this.bookList = new ArrayList<Book>();
    this.scanner = scanner;
  }

  // 도서 추가
  public void addBook() {
    System.out.print("도서명: ");
    String title = scanner.nextLine();
    System.out.print("저자: ");
    String author = scanner.nextLine();
    System.out.print("카테고리: ");
    String category = scanner.nextLine();
    System.out.print("가격: ");
    int price = scanner.nextInt();
    System.out.print("출간년도: ");
    int publishYear = scanner.nextInt();
    scanner.nextLine(); // 숫자 입력 후 줄바꿈 문자 처리
    Book book = new Book(title, author, category, price, publishYear);
    bookList.add(book);
    System.out.println("도서가 추가되었습니다.");
  }

  // 도서 목록 출력
  public void listBooks() {
    for (Book book : bookList) {
      System.out.println(book);
    }
  }

  // 도서 정보 수정 (여기서는 간단하게 도서명으로 검색하여 가격을 수정하는 예시를 듭니다)
  public void updateBook() {
    System.out.print("수정할 도서명: ");
    String title = scanner.nextLine();
    for (Book book : bookList) {
      if (book.getTitle().equals(title)) {
        System.out.print("새 가격: ");
        int newPrice = scanner.nextInt();
        scanner.nextLine(); // 숫자 입력 후 줄바꿈 문자 처리
        book.setPrice(newPrice);
        System.out.println("도서 가격이 수정되었습니다.");
        return;
      }
    }
    System.out.println("해당 도서를 찾을 수 없습니다.");
  }

  // 도서 삭제
  public void deleteBook() {
    System.out.print("삭제할 도서명: ");
    String title = scanner.next();
    for (Book book : bookList) {
      if (book.getTitle().equals(title)) {
        bookList.remove(book);
        System.out.println("도서가 삭제되었습니다..");
        return;
      }
    }
    System.out.println("해당 도서를 찾을 수 없습니다.");

  }
}