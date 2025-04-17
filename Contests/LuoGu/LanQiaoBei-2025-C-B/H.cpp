#include <bits/stdc++.h>

using i64 = long long;

const int mod = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);

    std::vector<int> pre(n + 1);

    int S = 0;
    i64 ans = 0;

    auto qp=[&](i64 a, i64 b) -> i64 {
        i64 res = 1;
        while(b > 0) {
            if(b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };

    for(int i = 1; i <= n; ++ i) {
        std::cin >> a[i];
        S ^= a[i];
        if(i < n) {
            ans += S * 2 * qp(3LL, n - i - 1) % mod;
        } else {
            ans += S;
        }
        ans %= mod;
    }

    std::cout << ans;
}