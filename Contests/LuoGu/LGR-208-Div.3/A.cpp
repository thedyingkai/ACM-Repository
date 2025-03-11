#include "iostream"
using namespace std;
int t,n,m,k,p;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>p;
        if((n>p&&k<=m)||(m-p/n)>=k) cout<<"Together"<<endl;
        else if(k>m) cout<<"Divide"<<endl;
        else cout<<"Chance"<<endl;
    }
    return 0;
}