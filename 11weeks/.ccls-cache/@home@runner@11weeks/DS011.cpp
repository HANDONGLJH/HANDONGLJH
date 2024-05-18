#include <iostream>

using namespace std;

// Function prototypes
void getNumbers(int *numbers, int count);
int calculateSum(int *numbers, int count);
int findMax(int *numbers, int count);

int main() {
  int count;

  // Get the number of integers to input
  cout << "Enter the number of integers: ";
  cin >> count;

  // Dynamically allocate array
  int *numbers = new int[count];

  // Input the numbers
  getNumbers(numbers, count);

  // Calculate the sum and find the maximum value
  int sum = calculateSum(numbers, count);
  int max = findMax(numbers, count);

  // Output the results
  cout << "Total sum: " << sum << endl;
  cout << "Maximum value: " << max << endl;

  // Free dynamically allocated memory
  delete[] numbers;

  return 0;
}

// Function to input numbers into the array
void getNumbers(int *numbers, int count) {
  cout << "Enter the integers:" << endl;
  for (int i = 0; i < count; ++i) {
    cout << "Number " << i + 1 << ": ";
    cin >> numbers[i];
  }
}

// Function to calculate the sum of the numbers in the array
int calculateSum(int *numbers, int count) {
  int sum = 0;
  for (int i = 0; i < count; ++i) {
    sum += numbers[i];
  }
  return sum;
}

// Function to find the maximum value in the array
int findMax(int *numbers, int count) {
  int max = numbers[0];
  for (int i = 1; i < count; ++i) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }
  return max;
}