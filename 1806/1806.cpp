#include <iostream>
#include <vector>
#include <limits>

int N, S;
std::vector<int> vec;

int solve() {
  int left = 0;
  int right = 0;
  int ans = std::numeric_limits<int>::max();

  do {
    const int& left_v = left == 0 ? 0 : vec[left - 1];
    const int& right_v = vec[right];

    const int sum = right_v - left_v;
    if(sum >= S) {
      ans = std::min(ans, right - left + 1);
      left++;
    } else {
      right++;
    }
  } while(left < N && right < N);

  return ans > N ? 0 : ans;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> S;

  vec.resize(N);
  
  std::cin >> vec[0];
  for(int i = 1; i < N; ++i) {
    std::cin >> vec[i];
    vec[i] += vec[i-1];
  }

  std::cout << solve();
}
