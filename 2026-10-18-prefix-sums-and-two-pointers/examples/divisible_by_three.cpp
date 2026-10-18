#include <algorithm>
#include <iostream>

// Самостоятельная реализация идеи с Miro, около 00–12 мин.
// На занятии эту программу НЕ писали: код оставлен как решение домашней задачи.
// Поскольку запись начинается в середине разбора, формат входа здесь принят
// для тренировки: n, затем n целых чисел; на выходе максимальная длина.
int main() {
    int n;
    std::cin >> n;
    long long prefix = 0;
    int first[3] = {0, -1, -1};
    int best = 0;

    for (int k = 1; k <= n; ++k) {
        long long value;
        std::cin >> value;
        prefix += value;
        int remainder = static_cast<int>((prefix % 3 + 3) % 3);
        if (first[remainder] == -1) {
            first[remainder] = k;
        } else {
            best = std::max(best, k - first[remainder]);
        }
    }
    std::cout << best << '\n';
}
