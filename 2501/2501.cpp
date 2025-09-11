#include <iostream>

int N, K;

int main(void) {
  std::cin >> N >> K;

  int cnt = 1;
  int ans = 0;
  for(int i = 1; cnt <= K && i <= N; ++i) {
    if(N % i != 0)
      continue;

    if(cnt == K) {
      ans = i;
      break;
    }
    cnt++;
  }

  std::cout << ans;
}
