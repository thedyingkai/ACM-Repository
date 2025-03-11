#include "iostream"
#include "cstring"
using namespace std;
int nn,m,a,b,c;
int main(){
    cin>>nn;
    while(nn--){
        cin>>m>>a>>b>>c;
        int res=0,n=m*2;
        if(m>=a){
            res+=a;
            n-=a;
        }
        else{
            res+=m;
            n-=m;
        }
        if(m>=b){
            res+=b;
            n-=b;
        }
        else{
            res+=m;
            n-=m;
        }
        if(n>=c) res+=c;
        else res+=n;
        cout<<res<<endl;
    }
}