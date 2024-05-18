#include <iostream>

using namespace std;

// 메뉴 구조체 정의
struct Menu {
  char name[100]; // 메뉴명 (공백 포함하지 않음)
  double price;   // 가격
};

// 카페 구조체 정의
struct Cafe {
  char name[100]; // 카페 이름 (공백 포함)
  int menuCount;  // 메뉴 개수
  Menu *menuList; // 메뉴 리스트 (포인터 변수)
};

// 함수 프로토타입 정의
void addCafe(Cafe &r1);
void addMenu(Menu &m1);
void displayMenus(const Cafe &r1);

int main() {
  Cafe cafe;

  // 카페 정보 입력받기
  addCafe(cafe);

  // 메뉴 리스트 동적 할당
  cafe.menuList = new Menu[cafe.menuCount];

  // 각 메뉴 입력받기
  for (int i = 0; i < cafe.menuCount; ++i) {
    cout << "Enter details for menu " << i + 1 << ":" << endl;
    addMenu(cafe.menuList[i]);
  }

  // 카페의 메뉴 출력
  displayMenus(cafe);

  // 동적 할당 메모리 해제
  delete[] cafe.menuList;

  return 0;
}

// 카페 정보를 입력받는 함수
void addCafe(Cafe &r1) {
  cout << "Enter the name of the cafe: ";
  cin.ignore(); // 이전 입력에서 남아 있는 개행 문자를 지움
  cin.getline(r1.name, 100); // 공백 포함된 카페 이름 입력받기
  cout << "Enter the number of menus: ";
  cin >> r1.menuCount;
  cin.ignore(); // 개행 문자 소모
}

// 메뉴 정보를 입력받는 함수
void addMenu(Menu &m1) {
  cout << "Menu name (no spaces): ";
  cin >> m1.name;
  cout << "Menu price: ";
  cin >> m1.price;
}

// 카페의 메뉴를 출력하는 함수
void displayMenus(const Cafe &r1) {
  cout << "Cafe Name: " << r1.name << endl;
  cout << "Menus:" << endl;
  for (int i = 0; i < r1.menuCount; ++i) {
    cout << "Menu " << i + 1 << ": " << r1.menuList[i].name << " - $"
         << r1.menuList[i].price << endl;
  }
}