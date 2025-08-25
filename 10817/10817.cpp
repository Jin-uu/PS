#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> in(3);

int main(void) {
  std::cin >> in[0] >> in[1] >> in[2];
  std::sort(in.begin(), in.end());

  std::cout << in[1];
}
