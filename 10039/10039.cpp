#include <iostream>

int main(void) {
  int in, sum = 0;
  for(int i = 0; i < 5; ++i) {
    std::cin >> in;
    sum += in < 40 ? 40 : in;
  }

  std::cout << sum / 5;
}
