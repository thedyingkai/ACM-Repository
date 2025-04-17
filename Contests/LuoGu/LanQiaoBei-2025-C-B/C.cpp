#include <bits/stdc++.h>
using i64 = long long;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);

    i64 ans = 0;

    for(int i = 1; i <= n; ++ i) {
        std::cin >> a[i];
        if(a[i] != 1) {
            ans ++;
        }
    }

    std::cout << ans;
}