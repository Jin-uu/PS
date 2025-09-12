#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

bool is_valid(const int a, const int b, const int c) {
  std::vector<int> vec{a, b, c};
  std::sort(vec.begin(), vec.end());

  if(vec[0] + vec[1] <= vec[2])
    return false;
  return true;
}

std::string solve(const int a, const int b, const int c) {
  if(!is_valid(a, b, c))
    return "Invalid";
  if(a == b && b == c)
    return "Equilateral";
  if(a != b && b != c && c != a)
    return "Scalene";
  return "Isosceles";
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int a, b, c;
  for(;;) {
    std::cin >> a >> b >> c;
    if(a == 0 && b == 0 && c == 0)
      break;
    std::cout << solve(a, b, c) << '\n';
  }
}

