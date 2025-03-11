#include "iostream"
using namespace std;
int n,l,r,T[100086],M[100086],t[100086],m[100086];
int main(){
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++) cin>>T[i]>>M[i];
    for(int i=1;i<=n;i++) cin>>t[i]>>m[i];
    for(int i=1;i<=n;i++){
        if(i>=l&&i<=r) cout<<"System Error"<<endl;
        else if(M[i]>m[i]) cout<<"Memory Limit Exceeded"<<endl;
        else if(T[i]/2>t[i]) cout<<"Time Limit Exceeded"<<endl;
        else cout<<"Accepted"<<endl;
    }
}