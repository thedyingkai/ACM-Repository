#include <bits/stdc++.h>
using namespace std;
int n,a[1001];
bool b[1000001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) b[abs(a[i]-a[i-1])]=1;
    for(int i=1;i<n;i++)if(!b[i]){
        cout<<"Not jolly";
        return 0;
    }
    cout<<"Jolly";
}