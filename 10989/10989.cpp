#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10'000'000
#define MAX_INPUT 10'000

int N;
std::vector<int> freq(MAX_INPUT+1, 0);

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  int input;
  for(int i = 0; i < N; i ++) {
    std::cin >> input;
    freq[input]++;
  }

  for(int i = 1; i <= MAX_INPUT; ++i) {
    for(int j = 0; j < freq[i]; j++)
      std::cout << i << '\n';
  }
}
