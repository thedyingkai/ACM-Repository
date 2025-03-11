//
// Created by ASUS on 2025/2/9.
//
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> a(n+1), b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(b.begin(),b.end());
    long long now=-0x3f3f3f3f3f3f3f3fLL;
    for(int i=1;i<=n;i++){
        long long num=a[i],nxt=0x3f3f3f3f3f3f3f3fLL;
        if(num>=now) nxt=min(nxt,num);
        auto it=lower_bound(b.begin()+1,b.end(),now+num);
        if(it!=b.end()) nxt=min(nxt,*it-num);
        if(nxt==0x3f3f3f3f3f3f3f3fLL){
            cout<<"NO\n";
            return;
        }
        now=nxt;
    }
    cout<<"YES\n";
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
}