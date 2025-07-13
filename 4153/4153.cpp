#include <iostream>
#include <vector>
#include <algorithm>

bool is_right_tri(std::vector<int>& lens) {
  std::sort(lens.begin(), lens.end());
  return lens[2] * lens[2] == lens[0] * lens[0] + lens[1] * lens[1];
}


int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b, c;
  for(;;) {
    std::cin >> a >> b >> c;
    if(a == 0)
      break;
    std::vector<int> lens = {a, b, c};
    if(is_right_tri(lens))
      std::cout << "right\n";
    else
      std::cout << "wrong\n";
  }
}
