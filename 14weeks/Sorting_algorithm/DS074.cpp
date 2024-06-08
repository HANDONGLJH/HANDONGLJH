#include <iostream>
#include <vector>
using namespace std;

// 디버그 매크로를 정의하여 정렬 과정을 출력
#ifdef DEBUG
#define DEBUG_PRINT(arr, size)        \
  do {                                \
    for (int i = 0; i < size; i++) {  \
      cout << "[" << arr[i] << "] ";  \
    }                                 \
    cout << endl;                     \
  } while (0)
#else
#define DEBUG_PRINT(arr, size)        \
  do {                                \
  } while (0)
#endif

    // 요소 두 개를 교환하는 함수
    void
    swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// 배열을 분할하는 함수
int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[high]; // 피봇 요소
  int i = (low - 1);     // 작은 요소의 인덱스

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
      DEBUG_PRINT(arr, arr.size());
    }
  }
  swap(arr[i + 1], arr[high]);
  DEBUG_PRINT(arr, arr.size());
  return (i + 1);
}

// 퀵 정렬 함수
void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int n;
  cin >> n; // 요소의 개수 입력
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  quickSort(arr, 0, n - 1);



  return 0;
}