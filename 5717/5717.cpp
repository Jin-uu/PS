#include <iostream>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int a, b;
  for(;;) {
    std::cin >> a >> b;
    if(a == 0 && b == 0)
      break;
    std::cout << a + b << '\n';
  }
}