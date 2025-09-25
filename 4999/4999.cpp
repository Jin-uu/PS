#include <iostream>
#include <string>

int main(void) {
  std::string a, b;
  std::cin >> a >> b;
  if(a.size() >= b.size())
    std::cout << "go";
    else
    std::cout << "no";
}
