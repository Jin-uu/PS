#include <iostream>
#include <string>

int CharToInt(const char ch) {
  if(ch >= 'W')
    return 9;
  if(ch >= 'T')
    return 8;
  if(ch >= 'P')
    return 7;
  if(ch >= 'M')
    return 6;
  if(ch >= 'J')
    return 5;
  if(ch >= 'G')
    return 4;
  if(ch >= 'D')
    return 3;
  if(ch >= 'A')
    return 2;
  return -1;    
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string in;
  std::cin >> in;

  int sum = 0;
  for(const auto& ch : in)
    sum += CharToInt(ch) + 1;
  std::cout << sum;
}
