#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> ta;
vector<vector<int>> adj;
bool check(const vector<int>& cur) {
    for(int i=0;i<n;++i)
        if(cur[i]!=ta[i]) return false;
    return true;
}
void toggle(vector<int>& stt,int node){
    stt[node]^=1;
    for(int nei:adj[node]) stt[nei]^=1;
}
int minSw(){
    int res=n+1;
    vector<int> ist(n,0);
    if(check(ist)) return 0;
    for(int mask=0;mask<(1<<n);++mask){
        vector<int> cur=ist;
        int cnt=0;
        for(int i=0;i<n;++i) if(mask&(1<<i)){
            toggle(cur,i);
            ++cnt;
            if(cnt>=res) break;
        }
        if(check(cur)) res=min(res,cnt);
    }
    return res==n+1?-1:res;
}
int main(){
    cin>>n;
    ta.resize(n);
    adj.resize(n);
    for(int i=0;i<n;++i) cin>>ta[i];
    for(int i=0;i<n-1;++i){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<minSw();
    return 0;
}