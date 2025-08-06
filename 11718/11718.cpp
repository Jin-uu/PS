#include <iostream>
#include <string>
#include <sstream>

constexpr int kMaxLine = 100;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    while (std::getline(std::cin, line)) {   // EOF까지 한 줄씩 읽기
        std::cout << line << '\n';      // 그대로 출력
    }
    return 0;
}
