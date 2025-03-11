#include "iostream"
using namespace std;
int T,n,s,t,res;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>s>>t;
        int tar=(1<<n)-1;
        if(s!=t) res=(tar^s)+(t^tar);
        else res=s^t;
        cout<<res<<endl;
    }
}