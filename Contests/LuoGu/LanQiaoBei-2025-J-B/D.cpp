#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), b(m + 1);
    std::vector<bool> pr(40001);
    for(int s = 0; s <= 40000; ++ s) {
        if(s <= 1) pr[s] = 1;
        for(int k = 2; k * k <= s; ++ k) {
            if(s % k == 0) {
                pr[s] = 1;
                break;
            }
        }
    }

    for(int i = 1; i <= n; ++ i) {
        std::cin >> a[i];
    }
    for(int i = 1; i <= m; ++ i) {
        std::cin >> b[i];
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::vector<bool> ans(40001,0);

    for(int i = 1; i <= n; ++ i) {
        if(a[i] > n + m) {
            break;
        }
        for(int j = 1; j <= m; ++ j) {
            if(a[i] + b[j] > n + m) {
                break;
            }
            else {
                if(!pr[a[i] + b[j]]) {
                    ans[a[i] + b[j]] = 1;
                }
            }
        }
    }

    i64 res = 0;
    for(auto it : ans) {
        if(it) {
            res ++;
        }
    }
    std::cout << res;
}