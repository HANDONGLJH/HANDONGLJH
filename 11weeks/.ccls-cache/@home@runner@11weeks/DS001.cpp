#include <cmath>
#include <iostream>

int main() {
  double x1, y1;
  double x2, y2;

  std::cout << "Enter the first coordinate (x1 y1): ";
  \n std::cin >> x1 >> y1;

  std::cout << "Enter the second coordinate (x2 y2): ";
  \n std::cin >> x2 >> y2;

  double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  std::cout << "The distance between the two points is: " << distance
            << std::endl;

  return 0;
}