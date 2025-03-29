#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,K;
    cin>>n>>m>>K;
    vector<long long> a(n+1),b(m+1),c(K+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=K;i++) cin>>c[i];
    long long ans=-1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=1;k<=K;k++){
        ans=max(ans,(a[i]%c[k]*b[j]%c[k])%c[k]);
    }
    cout<<ans;
}