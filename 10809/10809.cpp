#include <iostream>
#include <string>
#include <vector>

constexpr int kCharRange = 'z' - 'a' + 1;
std::vector<int> ans(kCharRange, -1);

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string in;
  std::cin >> in;

  for(int i = 0; i < in.size(); ++i) {
    const auto pos = in.at(i) - 'a';
    if(ans[pos] != -1)
      continue;
    ans[pos] = i;
  }
  
  for(const auto& elem : ans)
    std::cout << elem << ' ';
}
