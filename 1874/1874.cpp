#include <iostream>
#include <stack>
#include <queue>

#define MAX_N 100'000

int N, push_count = 0, pop_count = 0;
std::queue<int> q;
std::stack<int> stack;

std::vector<char> ans;

void push_stack() {
  push_count++;
  stack.push(push_count);
  ans.emplace_back('+');
}

void pop_stack() {
  pop_count++;
  stack.pop();
  ans.emplace_back('-');
}

void print_ans() {
  if(pop_count != N) {
    std::cout << "NO";
    return;
  }
  for(const auto& elem : ans)
   std::cout << elem << '\n';
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  int input;
  for(int i = 0; i < N; ++i) {
    std::cin >> input;
    q.push(input);
  }

  for(;;) {
    if(stack.empty()) {
      if(push_count >= N)
        break;
      else
        push_stack();
    }
    const auto& curr = stack.top();
    const auto& target = q.front();

    if(curr == target) {
      pop_stack();
      q.pop();
    } else {
      if(push_count >= N)
        break;
      push_stack();
    }
  }

  print_ans();
}
