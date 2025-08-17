#include <iostream>
#include <vector>

constexpr int kMaxN = 4'000'000;

int N;
std::vector<int> primes;
std::vector<bool> is_prime(kMaxN + 1, true);
std::vector<int> prime_sum;

void init() {
  is_prime[0] = false;
  is_prime[1] = false;
  for(int i = 2; i * i <= kMaxN; ++i) {
    if(is_prime[i])
      for(int j = i * i; j <= kMaxN; j += i)
        is_prime[j] = false;
  }

  for(int i = 0; i <= kMaxN; ++i)
    if(is_prime[i])
      primes.push_back(i);
  
  prime_sum.resize(primes.size());
  prime_sum[0] = primes[0];
  for(int i = 1; i < primes.size(); ++i)
    prime_sum[i] = primes[i] + prime_sum[i-1]; 
}

int solve() {
  int left = 0;
  int right = 0;
  int ans = 0;

  while(left <= right) {
    const auto& left_val = primes[left];
    const auto& right_val = primes[right];

    if(left_val > N)
      break;
    const auto& left_sum = left == 0 ? 0 : prime_sum[left - 1];
    const auto& right_sum = prime_sum[right];
    const int sum = right_sum - left_sum;
    if(sum == N) { 
      ans++;
      right++;
      continue;
    }
    if(sum < N)
      right++;
    else
      left++;
  }
  return ans;
}

int main(void) {
  init();

  std::cin >> N;
  std::cout << solve();
}
