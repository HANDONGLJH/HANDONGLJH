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
#define DEBUG_PRINT(arr, size)
#endif

    // 두 개의 하위 배열을 병합하는 함수
    void
    merge(vector<int> &arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // 임시 배열 생성
  vector<int> L(n1);
  vector<int> R(n2);

  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  // 임시 배열을 병합하여 원래 배열에 저장
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
    DEBUG_PRINT(arr, arr.size());
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
    DEBUG_PRINT(arr, arr.size());
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
    DEBUG_PRINT(arr, arr.size());
  }
}

// 병합 정렬 함수
void mergeSort(vector<int> &arr, int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = left + (right - left) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

int main() {
  int n;
  cin >> n; // 요소의 개수 입력
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  mergeSort(arr, 0, n - 1);

 
  return 0;
}