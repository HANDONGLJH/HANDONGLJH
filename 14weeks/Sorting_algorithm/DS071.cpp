#include <iostream>
using namespace std;

void print(int *arr, int n) {
  for (int i = 0; i < n; i++)
    cout << "[" << arr[i] << "] ";
  cout << endl;
}

void selectionSort(int *arr, int n) {
  int min_i = 0;

  for (int i = 0; i < n - 1; i++) {
    min_i = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[min_i] > arr[j])
        min_i = j;
    }
    if (i != min_i)
      swap(arr[i], arr[min_i]);

#ifdef DEBUG
    print(arr, n); // Debug 모드일 때 배열 출력
#endif
  }
}

int main() {
  int n;
  cout << ": ";
  cin >> n;

  int *arr = new int[n];
  cout << ": ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  print(arr, n);
  selectionSort(arr, n);

  delete[] arr;
  return 0;
}