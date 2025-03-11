#include "iostream"
using namespace std;
int n,a,b,c,to[101]={0},t,res=0;
int main(){
    cin>>n;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>t;
        to[t]++;
    }
    cin>>b;
    for(int i=0;i<b;i++){
        cin>>t;
        to[t]++;
    }
    cin>>c;
    for(int i=0;i<c;i++){
        cin>>t;
        to[t]++;
    }
    for(int i=1;i<n+1;i++){
        if(to[i]!=1) res++;
    }
    cout<<res;
}