#include "iostream"
using namespace std;
int T,n,a[100086],b[100086],sa=0,sb=0;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for (int i=0;i<n-1;++i){
            int d=b[i]-a[i];
            a[i+1]+=d;
        }
        if(a[n-1]!=b[n-1]) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}