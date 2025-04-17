#include <bits/stdc++.h>

struct circle {
    int x, y, r;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<circle> c(n + 1);

    double ans = 0.0;

    for(int i = 1; i <= n; ++ i) {
        std::cin >> c[i].x >> c[i].y >> c[i].r;

        if(i != 1) {
            bool flg = false;
            double Min = DBL_MAX;

            for(int j = 1; j < i; ++ j) {
                int dx = c[i].x - c[j].x;
                int dy = c[i].y - c[j].y;
                int ar = c[i].r + c[j].r;

                if(dx * dx + dy * dy <= ar * ar) {
                    flg = true;
                    break;
                }
                else Min = std::min(sqrt(dx * dx + dy * dy) - ar, Min);
            }
            if(! flg) {
                ans += Min;
            }
        }
    }
    std::cout.precision(3);
    std::cout << ans;
}