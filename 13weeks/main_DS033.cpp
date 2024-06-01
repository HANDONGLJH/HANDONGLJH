#include "CouponStack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int size;
    cout << "스택의 크기를 입력하세요: ";
    cin >> size;

    CouponStack stack(size);

    string command;
    cout << "명령을 입력하세요 (+(등수 상품명),-(등수 상품명) ,q(종료)): " << endl;

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