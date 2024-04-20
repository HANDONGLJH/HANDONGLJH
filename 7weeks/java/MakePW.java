import java.util.Random;

public class MakePW {
  private Random random; // Random 객체를 멤버 변수로 선언

  // 생성자
  public MakePW() {
    random = new Random(); // 생성자에서 Random 객체 초기화
  }

  // length 길이를 갖는 암호문자열 출력
  public void make(int length) {
    StringBuilder password = new StringBuilder();
    String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%&";

    for (int i = 0; i < length; i++) {
      int index = random.nextInt(characters.length());
      password.append(characters.charAt(index));
    }

    System.out.println(password.toString());
  }

  public void makeCode(int length1, int length2) {
    // 알파벳 대문자 부분 생성
    String alphabetPart = "";
    for (int i = 0; i < length1; i++) {
      char ch = (char) ('A' + random.nextInt(26));
      alphabetPart += ch;
    }
    // 숫자 부분 생성, 첫 번째 숫자가 0이 되지 않도록 한다.
    String numberPart = Integer.toString(1 + random.nextInt(9)); // 첫 번째 숫자 생성
    for (int i = 1; i < length2; i++) {
      numberPart += random.nextInt(10);
    }
    // 최종 코드 출력
    System.out.println(alphabetPart + "-" + numberPart);
  }

  public void make(int length, int amount) {
    Random random = new Random();
    for (int i = 0; i < amount; i++) {
      StringBuilder password = new StringBuilder();
      for (int j = 0; j < length; j++) {
        if (random.nextBoolean()) {
          // 알파벳 대문자(A-Z) 추가
          char ch = (char) ('A' + random.nextInt(26));
          password.append(ch);
        } else {
          // 숫자(0-9) 추가
          password.append(random.nextInt(10));
        }
      }
      System.out.println(password);
    }
  }
}