#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);

    int S = 0;

    for(int i = 1; i <= n; ++ i) {
        std::cin >> a[i];
        S ^= a[i];
    }

    if(S == 0) std::cout << "YES" << "\n";
    else std::cout << "NO" << "\n";
}

int main() {
    int t;
    std::cin >> t;
    while(t --) {
        solve();
    }
}