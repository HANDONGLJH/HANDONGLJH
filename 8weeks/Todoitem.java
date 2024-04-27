import java.util.Date;

public class TodoItem {
  private String title;
  private String detail;
  private Date reg_date;

  public TodoItem(String title, String detail) {
    this.title = title;
    this.detail = detail;
    this.reg_date = new Date(); // 현재 날짜와 시간으로 초기화
  }

  public String getTitle() {
    return title;
  }

  public void setTitle(String title) {
    this.title = title;
  }

  public String getDetail() {
    return detail;
  }

  public void setDetail(String detail) {
    this.detail = detail;
  }

  public Date getReg_date() {
    return reg_date;
  }

  public void setReg_date(Date reg_date) {
    this.reg_date = reg_date;
  }

  @Override
  public String toString() {
    return "Title: " + title + ", Detail: " + detail + ", Date: " + reg_date;
  }
}