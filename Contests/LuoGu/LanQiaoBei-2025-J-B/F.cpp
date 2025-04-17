#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1);
    i64 cnt = 0;
    std::vector<std::pair<int, i64>> pre;

    for(int i = 1; i <= n; ++ i) {
        std::cin >> a[i];
        if(a[i] == a[i - 1] || i == 1) {
            cnt ++;
        } else {
            pre.push_back({a[i - 1], cnt});
            cnt = 1;
        }
    }
    pre.push_back({a[n], cnt});

    std::sort(pre.begin(), pre.end(), [](auto x, auto y){
        if(x.first != y.first) return x.first < y.first;
        return x.second < y.second;
    });

    i64 Max = *max_element(a.begin(), a.end());
    for(int i = 1; i < pre.size(); ++ i) {
        if(pre[i].first == pre[i - 1].first) {
            Max = std::max(Max, (pre[i - 1].second + pre[i].second) * pre[i].first);
        }
    }

    std::cout << Max;
}