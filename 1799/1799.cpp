#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

constexpr int kMaxN = 10;

struct Coord {
  int row;
  int col;
};

int N;
std::vector<std::vector<int>> board(kMaxN + 1, std::vector<int>(kMaxN + 1));
std::vector<Coord> cells[2];      // 0: black, 1: white
bool diag1[kMaxN * 2 + 1];        // right-down diagonal
bool diag2[kMaxN * 2 + 1];        // right-upper diagonal
int ans[2];                       // 0: black, 1: white

inline bool can_place(const int row, const int col) {
  return !diag1[row + col] && !diag2[row - col + N];
}

void dfs(const int idx, const int cnt, const int color) {
  const int remain = (int)cells[color].size() - idx;
  if (cnt + remain <= ans[color])
    return;

  if (idx == (int)cells[color].size()) {
    ans[color] = std::max(ans[color], cnt);
    return;
  }

  const auto [r, c] = cells[color][idx];

  if (can_place(r, c)) {
    diag1[r + c] = true;
    diag2[r - c + N] = true;
    dfs(idx + 1, cnt + 1, color);
    diag1[r + c] = false;
    diag2[r - c + N] = false;
  }

  dfs(idx + 1, cnt, color);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      std::cin >> board[i][j];
      if (board[i][j]) cells[(i + j) % 2].push_back({i, j});
    }
  }
  memset(diag1, 0, sizeof(diag1));
  memset(diag2, 0, sizeof(diag2));
  ans[0] = ans[1] = 0;
  dfs(0, 0, 0);

  memset(diag1, 0, sizeof(diag1));
  memset(diag2, 0, sizeof(diag2));
  dfs(0, 0, 1);

  std::cout << ans[0] + ans[1];
  return 0;
}
