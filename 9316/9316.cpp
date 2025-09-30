#include <iostream>

int N;

int main(void) {
  std::cin >> N;
  for(int i = 0; i < N; ++i)
    std::cout << "Hello World, Judge " << i + 1 << "!\n";
}