#include <iostream>

int N;

int main(void) {
  const int year = 2024;
  const int month = 8;

  std::cin >> N;

  int ans_year = year + (month + (N - 1) * 7) / 12;
  int ans_month = (month + (N - 1) * 7) % 12;
  if(ans_month == 0) {
    ans_year--;
   ans_month = 12;
  }

  std::cout << ans_year << ' ' << ans_month;
}
