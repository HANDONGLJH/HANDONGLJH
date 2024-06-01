#include <iostream>
#include <string>

using namespace std;

// 쿠폰 정보를 담는 구조체 정의
struct Coupon {
  int rank;
  string reward;
};

// 쿠폰 관리를 위한 스택 클래스 정의
class CouponStack {
private:
  int maxsize;
  int top;
  Coupon *list;

public:
  CouponStack(int size = 10) : maxsize(size), top(-1) {
    list = new Coupon[maxsize];
  }

  ~CouponStack() { delete[] list; }

  void initialize() { top = -1; }

  bool isEmpty() const { return top == -1; }

  bool isFull() const { return top == maxsize - 1; }

  void push(const Coupon &coupon) {
    if (isFull()) {
      cout << "스택이 가득 찼습니다." << endl;
    } else {
      list[++top] = coupon;
    }
  }

  Coupon *pop() {
    if (isEmpty()) {
      cout << "스택이 비어 있습니다." << endl;
      return nullptr;
    } else {
      return &list[top--];
    }
  }

  void print() const {
    if (isEmpty()) {
      cout << "스택이 비어 있습니다." << endl;
    } else {
      for (int i = 0; i <= top; ++i) {
        cout << "등수: " << list[i].rank << ", 상품명: " << list[i].reward
             << endl;
      }
    }
  }

  void rprint() {
    while (!isEmpty()) {
      Coupon *coupon = pop();
      if (coupon != nullptr) {
        cout << "등수: " << coupon->rank << ", 상품명: " << coupon->reward
             << endl;
      }
    }
  }
};

int main() {
  int size;
  cout << "스택의 크기를 입력하세요: ";
  cin >> size;

  CouponStack stack(size);

  string command;
  cout << "명령을 입력하세요 (+(등수 상품명),-(등수 상품명) ,q(종료)): "
       << endl;

  while (cin >> command) {
    if (command == "+") {
      Coupon coupon;
      cin >> coupon.rank >> ws;
      getline(cin, coupon.reward);
      stack.push(coupon);
    } else if (command == "-") {
      Coupon *coupon = stack.pop();
      if (coupon != nullptr) {
        cout << "쿠폰 정보 - 등수: " << coupon->rank
             << ", 상품명: " << coupon->reward << endl;
      }
    } else if (command == "q") {
      break;
    } else {
      cout << "올바른 명령어를 입력하세요." << endl;
    }
  }

  cout << "프로그램 종료. 남은 쿠폰:" << endl;
  stack.print();

  return 0;
}