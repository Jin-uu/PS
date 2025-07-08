#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX_N 500'000
#define MAX_DATA 4000

int N, sum = 0;
std::vector<int> inputs;
std::vector<int> freqs(MAX_DATA * 2 + 1, 0);

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;
  inputs.resize(N);

  for(auto& elem : inputs) {
    std::cin >> elem;
    sum += elem;
    freqs[elem + MAX_DATA]++;
  }

  std::sort(inputs.begin(), inputs.end());

  int max_freq = *std::max_element(freqs.begin(), freqs.end());
  std::vector<int> max_freqs;
  for(int i = 0; i < freqs.size(); ++i) {
    const auto& curr = freqs[i];
    if(curr == max_freq)
      max_freqs.push_back(i - 4000);
  }

  const int round = std::round(static_cast<double>(sum) / static_cast<double>(N));
  std::cout << ((round == 0) ? 0 : round) << '\n';
  std::cout << inputs[N / 2] << '\n';
  if(max_freqs.size() == 1)
    std::cout << max_freqs[0] << '\n';
  else
    std::cout << max_freqs[1] << '\n';
  std::cout << inputs.back() - inputs.front() << '\n';
}

