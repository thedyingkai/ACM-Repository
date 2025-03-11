#include "iostream"
using namespace std;
int t,c,d;
int main(){
    cin>>t;
    while(t--) {
        cin >> c>>d;
        if (c == 0 && d == 0) cout << 0 << endl;
        else if (c == d) cout << 1 << endl;
        else if (max((c - d),(d-c)) % 2 == 0) cout << 2 << endl;
        else cout << -1 << endl;
    }
    return 0;
}