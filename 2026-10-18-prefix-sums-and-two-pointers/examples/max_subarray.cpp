#include <climits>
#include <iostream>

// Максимальная сумма непустого подотрезка. При равной сумме выбираем
// минимальный правый индекс, затем максимальный левый. Индексы с 1.
int main() {
    int n;
    std::cin >> n;

    long long prefix = 0;
    long long min_prefix = 0;
    int min_index = 0;  // prefix[0] — сумма пустого префикса.

    long long best_sum = LLONG_MIN;
    int best_left = 1;
    int best_right = 1;

    for (int right = 1; right <= n; ++right) {
        long long value;
        std::cin >> value;
        prefix += value;

        const long long candidate = prefix - min_prefix;
        // При равенстве оставляем прежний ответ: его правая граница меньше.
        if (candidate > best_sum) {
            best_sum = candidate;
            best_left = min_index + 1;
            best_right = right;
        }

        // При равных минимумах выбираем более поздний индекс начала.
        if (prefix <= min_prefix) {
            min_prefix = prefix;
            min_index = right;
        }
    }

    std::cout << best_left << ' ' << best_right << '\n';
}
