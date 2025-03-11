#include"iostream"
using namespace std;
int main(){
    int n,r=-1,l=10086;
    cin>>n;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a;
        r=max(a,r);
        l=min(a,l);
    }
    cout<<r-l;
    return 0;
}