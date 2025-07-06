#include <iostream>
#include <queue>

#define MAX_N 100

struct Doc {
  int weight;
  int location;
};

void solve() {
  int N, target_index;
  std::cin >> N >> target_index;

  std::queue<Doc> docs;
  std::priority_queue<int> priority;

  int weight;
  for(int i = 0; i < N; ++i) {
    std::cin >> weight;
    priority.push(weight);
    docs.push({weight, i});
  }

  int ans = 0;
  while(!docs.empty()) {
    const auto curr = docs.front();
    docs.pop();

    if(curr.weight == priority.top()) {
      priority.pop();
      ans++; 
      if(curr.location == target_index) {
        std::cout << ans << '\n';
        break;
      }
    }
    else {
      docs.push(curr);
    }
  }
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;
  for(int i = 0; i < T; ++i) {
    solve();
  }
}
