#include "iostream"
#include "algorithm"
using namespace std;
int T,n,a[100086];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    if(a[0]==a[n-1]){
        cout<<1<<endl;
        return;
    }
    for(int i=1;i<n-1;i++) if(a[i]==a[0]||a[i]==a[n-1]){
        cout<<2<<endl;
        return;
    }
    sort(a,a+n);
    for(int i=1;i<n-1;i++) if(a[i]==a[i+1]){
        cout<<3<<endl;
        return;
    }
    cout<<n<<endl;
    return;
}
int main(){
    cin>>T;
    while(T--){
        solve();
    }
}