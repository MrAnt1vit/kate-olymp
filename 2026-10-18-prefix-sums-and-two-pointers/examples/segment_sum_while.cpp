#include <iostream>
#include <vector>

// Поиск отрезка с суммой x: вариант while (true) из занятия, около 41–46 и 55–56 мин.
// В отличие от промежуточного кода на экране, пустое окно не считается ответом.
// Вход: n x, затем n неотрицательных чисел. Выход: границы с 1 или -1.
int main() {
    int n;
    long long x;
    std::cin >> n >> x;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    int l = 0, r = 0;
    long long ans = a[0];
    while (true) {
        if (ans == x) {
            std::cout << l + 1 << ' ' << r + 1 << '\n';
            return 0;
        }

        if (ans > x) {
            ans -= a[l];
            ++l;
            if (l == n) break;
            // После удаления единственного элемента окно стало пустым.
            if (l > r) {
                r = l;
                ans = a[r];
            }
        } else {
            ++r;
            if (r == n) break;
            ans += a[r];
        }
    }
    std::cout << -1 << '\n';
}
