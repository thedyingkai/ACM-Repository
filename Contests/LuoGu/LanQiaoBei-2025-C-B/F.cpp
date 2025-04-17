#include <bits/stdc++.h>

int main() {
    std::vector<std::string> map(2);
    std::cin >> map[0] >> map[1];

    bool first = false;

    int ans1 = 0;

    for(int i = 0; i < map[0].length(); ++ i) {
        if(map[1][i] == '.') {
            ans1 ++;
            if(map[0][i] == '.' && ! first) {
                ans1 --;
            } else {
                first = true;
            }
        }
    }

    bool last = false;

    for(int i = map[0].length() - 1; i >= 0; -- i) {
        if(map[1][i] == '.') {
            if(map[0][i] == '.' && ! last) {
                ans1 --;
            } else {
                break;
            }
        }
    }
    std::cout << ans1;
}