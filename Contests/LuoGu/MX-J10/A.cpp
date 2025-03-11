#include "iostream"
using namespace std;
int T,n,a,b,sa=0,sb=0;
int main(){
    cin>>n>>T;
    for(int i=0;i<n;i++){
        cin>>a;
        sa+=a;
    }
    if(sa<T) cout<<sa;
    else{
        for(int i=0;i<n;i++){
            cin>>b;
            sb+=b;
        }
        cout<<sb;
    }
}