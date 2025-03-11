#include "iostream"
using namespace std;
int t,n;
char a[100086];

int main() {
    cin >> t;
    while (t--) {
        cin>>n;
        cin>>a;
        bool s=0;
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]&&s!=1) {
                cout <<i<<" "<<i+1<<endl;
                s=1;
            }
        }
        if(!s) cout <<"-1 -1"<<endl;
    }
    return 0;
}