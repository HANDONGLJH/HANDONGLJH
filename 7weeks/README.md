# Java Utilities Overview

##도서 관리

###Book.java
기능: 도서 정보(제목, 저자, 카테고리, 가격, 출간년도)를 나타내는 클래스입니다.
주요 메서드: 생성자, getter 및 setter 메서드, toString() 메서드.

###BookCRUD.java
기능: 도서 정보의 추가, 목록 조회, 수정, 삭제를 관리합니다.
주요 메서드: addBook(), listBooks(), updateBook(), deleteBook().

###BookMain.java
기능: 도서 관리 프로그램의 메인 클래스입니다. 사용자 입력을 받아서 적절한 도서 관리 기능을 수행합니다.
주요 메서드: main() 메서드.



##단어 관리

###Word.java
기능: 단어 정보를 나타내는 클래스입니다.
주요 속성: 단어와 그 의미.

###WordCRUD.java
기능: 단어 정보의 추가, 목록 조회, 수정, 삭제를 관리합니다.
주요 메서드: addWord(), listWords(), updateWord(), deleteWord().

###Main.java
기능: 단어 관리 프로그램의 메인 클래스입니다. 사용자 입력에 따라 단어 관리 기능을 실행합니다.
주요 메서드: main() 메서드.
문자열 처리 및 성적 계산



##Main7.java
기능: 성적 계산 프로그램의 메인 클래스입니다. 학생 성적 입력 및 처리 관련 기능을 실행합니다.
주요 메서드: main() 메서드.

###MyString.java
기능: 문자열을 처리하는 다양한 메서드를 포함합니다.
주요 메서드: 문자열 처리와 관련된 메서드.

###Score.java
기능: 학생의 과목별 점수, 총점, 평균을 계산합니다.
주요 메서드: getScore(), printScore(), printScore(int num), printScore(int num, String classname).
