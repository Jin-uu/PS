#include <iostream>
#include <vector>
#include <algorithm>

using it = std::vector<int>::iterator;

int N;
std::vector<int> in;
std::vector<int> post;

void solve(const it in_left, const it in_right, const it post_left, const it post_right) {
  if(in_left > in_right || post_left > post_right)
    return;
  const int root = *post_right;
  std::cout << root << ' ';

  const it new_root = std::find(in_left, in_right, root);
  
  const int left_size = std::distance(in_left, new_root);
  const int right_size = std::distance(new_root, in_right);

  solve(in_left, new_root - 1, post_left, post_left + left_size - 1);
  solve(new_root + 1, in_right, post_left + left_size, post_right - 1 );
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  in.resize(N);
  post.resize(N);
  for(int i = 0; i < N; ++i)
    std::cin >> in[i];
  for(int i = 0; i < N; ++i)
    std::cin >> post[i];

  solve(in.begin(), in.end() - 1, post.begin(), post.end() - 1);
}
