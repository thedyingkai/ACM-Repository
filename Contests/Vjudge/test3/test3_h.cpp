#include "iostream"
#include "cstring"
using namespace std;
int t,n;
int a[100086];
bool b[100086];
bool c[100086];
int resa(bool bb) {
    int rr = 0;
    if (b[0] != bb) for (int i = 1;; i++) {
        if (b[i] == bb) {
            rr += i;
            b[i] = !bb;
            b[0] = bb;
            break;
        }
    }
    for (int i = 1; i < n; i++){
        if (b[i] == b[i - 1]) for (int j = i+1;j<n; j++) {
            if(b[j] != b[i]) {
                rr += j - i;
                b[j] = !b[j];
                b[i] = !b[i];
                break;
            }
        }
    }
    return rr;
}
int resb(bool bb) {
    int rr = 0;
    if (c[0] != bb) for (int i = 1;; i++) {
            if (c[i] == bb) {
                rr += i;
                c[i] = !bb;
                c[0] = bb;
                break;
            }
        }
    for (int i = 1; i < n; i++){
        if (c[i] == c[i - 1]) for (int j = i+1;j<n; j++) {
                if(c[j] != c[i]) {
                    rr += j - i;
                    c[j] = !c[j];
                    c[i] = !c[i];
                    break;
                }
            }
    }
    return rr;
}
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        int q = 0, w = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] & 1) {
                w++;
                b[i] = 1;
                c[i]=1;
            } else {
                q++;
                b[i] = 0;
                c[i]=0;
            }
        }
        if (n == 1) cout << 0 << endl;
        else {
            if (!(q - w == 0 || q - w == -1 || q - w == 1)) {
                cout << -1 << endl;
                continue;
            }
            int ans;
            if (n & 1) {
                if (w > q) ans = resa(1);
                else ans = resa(0);
            } else {
                ans = min(resa(0), resb(1));
            }
            cout <<ans<<endl;
        }
    }
    return 0;
}