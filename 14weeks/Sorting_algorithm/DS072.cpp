#include <iostream>
using namespace std;

// 배열의 상태를 출력하는 함수
void print(int *arr, int n) {
  for (int i = 0; i < n; i++)
    cout << "[" << arr[i] << "] ";
  cout << endl;
}

// insertion sort 함수
void insertionSort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;

#ifdef DEBUG
    print(arr, n); // Debug 모드일 때 배열 출력
#endif
  }
}

int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int *arr = new int[n];
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // 초기 배열 상태 출력
  print(arr, n);
  insertionSort(arr, n);

  delete[] arr;
  return 0;
}