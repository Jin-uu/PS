#include <iostream>
#include <vector>
#include <string>

using ll = long long;

int N;
std::vector<ll> ans(10, 0);

int calc(const int high, const int curr, const int low, const int digit, const int target) {
  int ret = 0;
  ret += high * digit;
  if(target == curr)
    ret += low + 1;
  else if(target < curr)
    ret += digit;
  
  return ret;
}

int count_target(int digit, int target) {
  const int high = N / (digit * 10);
  const int curr = N / digit % 10;
  const int low = N % digit;  
  return calc(high, curr, low, digit, target);
}

int count_target_0(int digit) {
  const int high = N / (digit * 10) - 1;
  const int curr = N / digit % 10;
  const int low = N % digit;
  if(std::to_string(digit).size() == std::to_string(N).size())
    return 0;
  
  return calc(high, curr, low, digit, 0);
}

void solve() {
  const int digit_bound = std::to_string(N).size();
  for(int i = 0; i <= 9; ++i)
    for(int j = 1; j <= N; j *= 10)
      ans[i] += (i == 0) ? count_target_0(j) : count_target(j, i);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  solve();

  for(int i = 0; i <= 9; ++i)
    std::cout << ans[i] << ' ';
}
