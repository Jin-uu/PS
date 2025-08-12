#include <iostream>
#include <string>
#include <vector>

constexpr int kAlpBound = 'Z' - 'A' + 1;
std::vector<int> alp(kAlpBound, 0);

char ToUpper(const char in) {
  if('a' <= in && in <= 'z')
    return in + 'A' - 'a';
  return in;
}

int main(void) {
  std::string in;
  std::cin >> in;

  for(const auto& elem : in) {
    alp[ToUpper(elem) - 'A']++;
  }
  
  int max = -1;
  char ans = '?';
  for(int i = 0; i < kAlpBound; i++) {
    const auto& curr = alp[i];
    if(max <= curr) {
      if(max == curr) {
        ans = '?';
        continue;
      }
      max = curr;
      ans = static_cast<char>(i + 'A');
    }
  }
  std::cout << ans;
}
