#include <iostream>
#include <algorithm>
using namespace std;
int n, m, s[5010][5010];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int x, y, v;
        cin >> x >> y >> v;
        s[x + 1][y + 1] += v;
    }
    int N = 5001;
    for (int i = 1; i <= N; i ++)
        for (int j = 1; j <= N; j ++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
    int ans = 0;
    for (int i = m; i <= N; i ++)
        for (int j = m; j <= N; j ++) {
            int num = s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m];
            ans = max(ans, num);
        }
    cout << ans << endl;
    return 0;
}
