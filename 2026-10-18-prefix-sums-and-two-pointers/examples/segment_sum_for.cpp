#include <iostream>
#include <vector>

// Поиск отрезка с суммой x: внешний for по l, вложенный while по r.
// Структура повторяет второй вариант из занятия, около 47–54 мин.
// Вход: n x, затем n неотрицательных чисел. Выход: границы с 1 или -1.
int main() {
    int n;
    long long x;
    std::cin >> n >> x;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    int r = 0;
    long long ans = a[0];
    for (int l = 0; l < n; ++l) {
        if (l > 0) ans -= a[l - 1];
        // На записи этот случай отдельно не оформлялся: не оставляем пустое окно.
        if (r < l) {
            r = l;
            ans = a[r];
        }
        while (ans < x && r < n - 1) {
            ++r;
            ans += a[r];
        }
        if (ans == x) {
            std::cout << l + 1 << ' ' << r + 1 << '\n';
            return 0;
        }
    }
    std::cout << -1 << '\n';
}
