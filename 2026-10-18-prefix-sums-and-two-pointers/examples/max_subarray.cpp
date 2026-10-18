#include <climits>
#include <iostream>
#include <vector>

// Рабочая версия алгоритма, который писали на занятии.
// Сохранены p, imin, ibest, jbest и порядок проверок в одном цикле.
int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n), p(n + 1, 0);

    int imin = 0;
    int ibest = 0, jbest = 0;
    long long best_sum = LLONG_MIN;

    for (int j = 0; j < n; ++j) {
        std::cin >> a[j];
        p[j + 1] = p[j] + a[j];

        // Включаем p[j], но ещё не p[j+1]: отрезок должен быть непустым.
        if (p[j] <= p[imin]) imin = j;

        long long candidate = p[j + 1] - p[imin];
        if (candidate > best_sum) {
            best_sum = candidate;
            ibest = imin;
            jbest = j;
        }
    }

    std::cout << ibest + 1 << ' ' << jbest + 1 << '\n';
}
