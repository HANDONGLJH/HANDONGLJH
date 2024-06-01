#include <iostream>

using namespace std;

class Product {
private:
  char name[100];         // 상품명 (최대 100 글자)
  double originalPrice;   // 원래 가격
  double discountRate;    // 할인율
  char manufacturer[100]; // 제조사 (최대 100 글자)
  double size;            // 크기

public:
  Product() : originalPrice(0), discountRate(0), size(0) {
    name[0] = '\0';
    manufacturer[0] = '\0';
  }

  // 멤버 함수: 상품 정보 입력
  void input() {
    cout << "상품명을 입력하세요 (공백 포함 가능): ";
    cin.ignore(); // 입력 버퍼 초기화
    cin.getline(name, 100);

    cout << "가격을 입력하세요: ";
    cin >> originalPrice;

    cout << "할인율을 입력하세요 (백분율로 입력 예: 10): ";
    cin >> discountRate;

    cout << "제조사를 입력하세요: ";
    cin.ignore(); // 공백 포함 입력받기 위해 버퍼 초기화
    cin.getline(manufacturer, 100);

    cout << "크기를 입력하세요: ";
    cin >> size;
  }

  // 멤버 함수: 할인된 가격 계산
  double calculateDiscountPrice() const {
    return originalPrice * (1 - discountRate / 100);
  }

  // 멤버 함수: 상품 정보 출력
  void print() const {
    cout << "상품명: " << name << endl;
    cout << "원래 가격: " << originalPrice << endl;
    cout << "할인율: " << discountRate << "%" << endl;
    cout << "제조사: " << manufacturer << endl;
    cout << "크기: " << size << endl;
    cout << "할인된 가격: " << calculateDiscountPrice() << endl;
  }
};

class ProductManager {
private:
  Product **products; // 상품 리스트를 저장하는 동적 배열
  int productCount;   // 현재 저장된 상품 개수

public:
  ProductManager() : products(nullptr), productCount(0) {}

  ~ProductManager() {
    // 소멸자: 동적으로 할당된 메모리를 해제
    for (int i = 0; i < productCount; ++i) {
      delete products[i];
    }
    delete[] products;
  }

  // 상품 추가 메소드
  void addProduct() {
    Product *newProduct = new Product(); // 새로운 상품 객체 생성
    newProduct->input();                 // 상품 정보 입력

    // 기존의 배열 확장을 위해 새로운 배열 생성
    Product **newProducts = new Product *[productCount + 1];
    for (int i = 0; i < productCount; ++i) {
      newProducts[i] = products[i];
    }
    newProducts[productCount] = newProduct;

    // 기존 배열 삭제 및 포인터 갱신
    delete[] products;
    products = newProducts;
    ++productCount;
  }

  // 상품 목록 출력 메소드
  void printProducts() const {
    for (int i = 0; i < productCount; ++i) {
      products[i]->print();
      cout << "-----------------------------" << endl;
    }
  }
};

int main() {
  ProductManager manager; // 상품 관리 객체 생성
  int choice;             // 사용자 선택

  while (true) {
    cout << "메뉴: 1. 상품 추가 2. 상품 3.목록 출력 0. 종료" << endl;
    cout << "선택하세요: ";
    cin >> choice;

    if (choice == 1) {
      manager.addProduct(); // 상품 추가
    } else if (choice == 2) {
      manager.printProducts(); // 상품 목록 출력
    } else if (choice == 0) {
      break; // 프로그램 종료
    } else {
      cout << "올바른 선택을 하세요." << endl;
    }
  }

  return 0;
}