#include <iostream>
#include <vector>

// Подсчитать неупорядоченные пары разных памятников на расстоянии > limit.
// Координаты во входе строго возрастают.
int main() {
    int n;
    long long limit;
    std::cin >> n >> limit;
    std::vector<long long> position(n);
    for (auto& value : position) {
        std::cin >> value;
    }

    long long answer = 0;
    int right = 1;
    for (int left = 0; left < n; ++left) {
        if (right <= left) {
            right = left + 1;
        }
        while (right < n && position[right] - position[left] <= limit) {
            ++right;
        }
        // Все позиции от right до n-1 находятся достаточно далеко.
        answer += n - right;
    }

    std::cout << answer << '\n';
}
