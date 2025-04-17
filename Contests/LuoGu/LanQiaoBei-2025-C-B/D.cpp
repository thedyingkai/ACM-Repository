#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;

    while(t --) {
        int a, b, c, k;
        std::cin >> a >> b >> c >> k;

        bool flg = false;

        while(k --) {
            int a_new = (b + c) / 2;
            int b_new = (a + c) / 2;
            int c_new = (a + b) / 2;

            a = a_new, b = b_new, c = c_new;
            if(a == b && a == c) {
                std::cout << a << " " << b << " "<< c << "\n";
                flg = true;
                break;
            }
        }

        if(! flg) {
            std::cout << a << " " << b << " "<< c << "\n";
        }
    }
}