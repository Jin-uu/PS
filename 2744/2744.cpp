#include <iostream>
#include <string>

char to_bigger(const char ch) {
  return ch - ('a' - 'A');
}
char to_less(const char ch) {
  return ch + ('a' - 'A');
}

int main(void) {
  std::string in;
  std::cin >> in;

  for(const auto& ch : in) {
    if(ch >= 'a')
      std::cout << to_bigger(ch);
    else 
      std::cout << to_less(ch);
  }
}
