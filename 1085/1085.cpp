#include <iostream>
#include <cmath>
#include <algorithm>

int x, y, w, h;

int main(void) {
  std::cin >> x >> y >> w >> h;
  std::cout << std::min(std::min(x, y), std::min(std::abs(x - w), std::abs(y - h)));
}
