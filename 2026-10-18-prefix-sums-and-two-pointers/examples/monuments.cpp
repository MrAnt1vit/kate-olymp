#include <iostream>
#include <vector>

// «Город Че»: законченная версия наброска с внешним for из конца занятия.
// Считаем пары на расстоянии <= x, затем вычитаем их из числа всех пар.
// Отличие от экрана: счётчики пар имеют тип long long.
int main() {
    int n;
    long long x;
    std::cin >> n >> x;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    int r = 0;
    long long diff = 0;
    long long near_pairs = 0;
    for (int l = 0; l < n; ++l) {
        if (l != 0) diff -= a[l] - a[l - 1];
        while (diff <= x && r < n) {
            ++r;
            if (r != n) diff += a[r] - a[r - 1];
        }
        near_pairs += r - l - 1;
    }

    long long all_pairs = 1LL * n * (n - 1) / 2;
    std::cout << all_pairs - near_pairs << '\n';
}
