#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n + 1);
    for(int i = 1; i <= n; ++ i) {
        std::cin >> p[i];
    }

    i64 res = 0;

    std::vector<bool> vis(n + 1, 0);
    for(int i = n; i >= 1; -- i) {
        bool flg = false;

        for(int j = n; j > p[i]; -- j) {
            if(! vis[j]) {
                flg = true;
                vis[j] = 1;
                res += i ;
                break;
            }
        }

        if(! flg) {
            for(int j = 1; j <= p[i]; ++ j) {
                if(! vis[j]) {
                    vis[j] = 1;
                    res -= i;
                    break;
                }
            }
        }
    }
    std::cout << res;
}