#include <iostream>

int main(void) {
  int sum = 0;
  int in;
  for(int i = 0; i < 5; ++i) {
    std::cin >> in;
    sum += in;
  }
  std::cout << sum;
}
