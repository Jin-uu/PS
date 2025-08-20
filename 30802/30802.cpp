#include <iostream>
#include <vector>

int N, T, P;
std::vector<int> shirts(6);

int main(void) {
  std::cin >> N;
  for(int i = 0; i < 6; ++i)
    std::cin >> shirts[i];
  std::cin >> T >> P;

  int shirts_sum = 0;
  for(const auto& elem : shirts) {
    shirts_sum += elem / T;
    if(elem % T != 0)
      shirts_sum++;
  }
  std::cout << shirts_sum << std::endl;
  std::cout << N / P << ' ' << N % P;
}
