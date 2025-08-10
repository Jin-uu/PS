#include <iostream>
#include <vector>

std::vector<int> board = {1, 1, 2, 2, 2, 8};

int main(void) {
  std::vector<int> in(board.size());
  for(int i =0; i < 6; ++i)
    std::cin >> in[i];
  
  for(int i = 0; i < 6; ++i)
    std::cout << board[i] - in[i] << ' ';   
}
