public class Book {
  private String title; // 도서명
  private String author; // 저자
  private String category; // 카테고리
  private int price; // 가격
  private int publishYear; // 출간년도

  // 모든 도서 정보로 생성하는 생성자
  public Book(String title, String author, String category, int price, int publishYear) {
    this.title = title;
    this.author = author;
    this.category = category;
    this.price = price;
    this.publishYear = publishYear;
  }

  // 도서명만으로 생성하는 생성자
  public Book(String title) {
    this.title = title;
  }

  // Getter와 Setter 메소드들
  public String getTitle() {
    return title;
  }

  public void setTitle(String title) {
    this.title = title;
  }

  public String getAuthor() {
    return author;
  }

  public void setAuthor(String author) {
    this.author = author;
  }

  public String getCategory() {
    return category;
  }

  public void setCategory(String category) {
    this.category = category;
  }

  public int getPrice() {
    return price;
  }

  public void setPrice(int price) {
    this.price = price;
  }

  public int getPublishYear() {
    return publishYear;
  }

  public void setPublishYear(int publishYear) {
    this.publishYear = publishYear;
  }

  // 멤버 정보를 문자열로 리턴하는 toString() 메소드
  @Override
  public String toString() {
    return "Book{" +
        "title='" + title + '\'' +
        ", author='" + author + '\'' +
        ", category='" + category + '\'' +
        ", price=" + price +
        ", publishYear=" + publishYear +
        '}';
  }
}