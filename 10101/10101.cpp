#include <iostream>
#include <string>

std::string solve(const int a, const int b, const int c) {
  if(a == 60 && b == 60 && c == 60)
    return "Equilateral";
  if(a + b + c != 180)
    return "Error";
  if(a == b || b == c || c == a)
    return "Isosceles";
  return "Scalene";
}


int main(void) {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << solve(a, b, c);
}
