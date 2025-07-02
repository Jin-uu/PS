#include <iostream>
#include <deque>
#include <vector>
#include <limits>

#define MAX_N 100'000
#define MAX_K 100'000

constexpr int INF_INT = std::numeric_limits<int>::max();

int N, K;
// dist[i] = N으로부터의 i까지의 최소 step
std::vector<int> dist(MAX_N + 1, INF_INT); 

bool is_valid_loc(int loc) {
  return 0 <= loc && loc <= MAX_N;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> K;

  std::deque<int> dq;
  dq.push_front(N);
  dist[N] = 0;

  for(;;) {
    const auto curr = dq.front();
    dq.pop_front();

    if(curr == K)
      break;
    
    // step -1
    {
      const auto next = curr - 1;
      if(is_valid_loc(next)) {
        if(dist[next] > dist[curr] + 1) {
          dq.push_back(next);
          dist[next] = dist[curr] + 1;
        }
      }
    }
    // step +1
    {
      const auto next = curr + 1;
      if(is_valid_loc(next)) {
        if(dist[next] > dist[curr] + 1){
          dq.push_back(next);
          dist[next] = dist[curr] + 1;
        }
      }
    }
    // step *2
    {
      const auto next = curr * 2;
      if(is_valid_loc(next)) {
        if(dist[next] > dist[curr]) {
          dq.push_back(next);
          dist[next] = dist[curr];
        }
      }
    }
  }

  std::cout << dist[K];
}
