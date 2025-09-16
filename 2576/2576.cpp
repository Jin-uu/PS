#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> vec;

int main(void) {
  int in;
  for(int i = 0; i < 7; ++i) {
    std::cin >> in;
    if(in % 2 != 0)
      vec.push_back(in);
  }

  if(vec.empty()) {
    std::cout << -1;
    return 0;
  }

  std::sort(vec.begin(), vec.end());
  std::cout << std::accumulate(vec.begin(), vec.end(), 0) << '\n';
  std::cout << vec[0];
}
