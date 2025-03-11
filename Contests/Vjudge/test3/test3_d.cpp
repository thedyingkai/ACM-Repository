#include "iostream"
#include "algorithm"
using namespace std;
int t,n,s,m;
struct st{
    int a,i;
}a[100005],b[100005];
int main(){
    cin>>t;
    while(t--){
        m=1e6,s=1e6;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a;
            a[i].i=i;
        }
        for(int i=1;i<=n;i++){
            cin>>b[i].a;
            b[i].i=i;
        }
        sort(a+1,a+n+1,[](st x,st y){return x.a<y.a;});
        sort(b+1,b+n+1,[](st x,st y){return x.a<y.a;});
        for(int i=1;i<=n;i++) {
            m=min(m,a[i].i);
            s=min(s,m+b[i].i);
        }
        cout<<s-2<<endl;
    }
    return 0;
}