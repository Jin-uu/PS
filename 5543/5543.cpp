#include <iostream>
#include <limits>
#include <cmath>

int main(void) {
  int A = std::numeric_limits<int>::max();
  int B = std::numeric_limits<int>::max();

  int in;
  for(int i = 0; i < 3; ++i) {
    std::cin >> in;
    A = std::min(A, in);
  }
  for(int i = 0; i < 2; ++i) {
    std::cin >> in;
    B = std::min(B, in);
  }
  std::cout << A + B - 50;
}
