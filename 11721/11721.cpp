#include <iostream>
#include <string>

int main(void) {
  std::string in;
  std::cin >> in;

  int idx = 0;
  for(;;) {
    for(int i = idx; i < idx + 10 && i < in.size(); ++i)
      std::cout << in[i];

    if(idx >= in.size())
      break;
    idx += 10;
    std::cout << std::endl;
  }
}
