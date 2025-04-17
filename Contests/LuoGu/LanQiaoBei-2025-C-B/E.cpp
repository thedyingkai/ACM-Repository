#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n + 1);

    for(int i = 1; i <= n; ++ i) {
        std::cin >> a[i];
        a[i] *= a[i];
    }

    std::sort(a.begin(), a.end(), std::less<>());

    i64 Min = LLONG_MAX;

    for(int i = 1; i <= n - m + 1; ++ i) {
        Min = std::min(Min, a[i + m - 1] - a[i]);
    }

    std::cout << Min;
}