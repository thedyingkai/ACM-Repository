#include "iostream"
using namespace std;
long long int n,a,b,res=0;
int main(){
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(b==0) res+=20;
        else res+=a;
    }
    cout<<res;
}