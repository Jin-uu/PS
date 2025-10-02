#include <iostream>
#include <iomanip>

int main(void) {
  int W, H;
  std::cin >> W >> H;

  std::cout << std::fixed << std::setprecision(1);
  std::cout << static_cast<float>(W * H) / 2;
}