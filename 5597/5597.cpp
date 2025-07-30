#include <iostream>
#include <vector>

constexpr int kStudentNumber = 30;
constexpr int kMaxSubmit = 28;


std::vector<int> checklist(kStudentNumber+1, 0);

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int num;
  for(int i = 0; i < kMaxSubmit; ++i) {
    std::cin >> num;
    checklist[num] = 1;
  }
  
  for(int i = 1; i <= kStudentNumber; ++i)
    if(!checklist[i])
      std::cout << i << std::endl;
}
