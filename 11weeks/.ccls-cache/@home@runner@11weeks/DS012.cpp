#include <iostream>

using namespace std;

// 상품 정보를 담는 구조체 정의
struct Product {
  char name[100];         // 상품 이름
  double price;           // 가격
  char manufacturer[100]; // 제조사
};

// 함수 프로토타입 정의
bool compareProducts(const Product *p1, const Product *p2);
void toLowerCase(char *str);
void copyString(char *dest, const char *src);
int compareString(const char *str1, const char *str2);

int main() {
  Product product1, product2;

  // 첫 번째 상품 정보 입력
  cout << "Enter the name of the first product: ";
  cin.getline(product1.name, 100);
  cout << "Enter the price of the first product: ";
  cin >> product1.price;
  cin.ignore(); // 개행 문자 소모
  cout << "Enter the manufacturer of the first product: ";
  cin.getline(product1.manufacturer, 100);

  // 두 번째 상품 정보 입력
  cout << "Enter the name of the second product: ";
  cin.getline(product2.name, 100);
  cout << "Enter the price of the second product: ";
  cin >> product2.price;
  cin.ignore(); // 개행 문자 소모
  cout << "Enter the manufacturer of the second product: ";
  cin.getline(product2.manufacturer, 100);

  // 두 상품을 비교하여 결과 출력
  if (compareProducts(&product1, &product2)) {
    cout << "The products are the same: " << product1.name << endl;
  } else {
    cout << "The products are different." << endl;
  }

  return 0;
}

// 두 상품을 비교하는 함수
bool compareProducts(const Product *p1, const Product *p2) {
  // 가격이 다르면 다른 상품으로 판단
  if (p1->price != p2->price) {
    return false;
  }

  char name1[100], name2[100];

  // 상품 이름 복사 후 소문자로 변환
  copyString(name1, p1->name);
  copyString(name2, p2->name);

  toLowerCase(name1);
  toLowerCase(name2);

  // 상품 이름이 같으면 같은 상품으로 판단
  if (compareString(name1, name2) == 0) {
    return true;
  } else {
    return false;
  }
}

// 문자열을 소문자로 변환하는 함수
void toLowerCase(char *str) {
  for (int i = 0; str[i]; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 'a' - 'A';
    }
  }
}

// 문자열을 복사하는 함수
void copyString(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0'; // 문자열 끝에 null 문자 추가
}

// 문자열을 비교하는 함수
int compareString(const char *str1, const char *str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) {
      return str1[i] - str2[i];
    }
    i++;
  }
  return str1[i] - str2[i];
}