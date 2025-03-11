#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=200005;
struct eg{
    ll to;
    ll dir;
};
ll s[maxn],p[maxn],q[maxn],u[maxn],v[maxn];
vector<eg> egs[maxn];
void add_edge(ll u,ll v){
    egs[u].push_back({v,1});
    egs[v].push_back({u,0});
}
void dfs(ll k,ll fa=-1){
    if(egs[k].size()==1 && egs[k][0].to==fa){
        s[k]=0;
        p[k]=0;
        q[k]=0;
        u[k]=0;
        v[k]=0;
        return;
    }
    for (auto eg:egs[k]){
        if(eg.to==fa) continue;
        dfs(eg.to,k);
        if(eg.dir){
            q[k]+=q[eg.to]+1;
            v[k]+=v[eg.to]+q[eg.to]+1;
        }
        else{
            p[k]+=p[eg.to]+1;
            u[k]+=u[eg.to]+p[eg.to]+1;
        }
        s[k]+=s[eg.to];
    }
    s[k]+=p[k]*v[k]+q[k]*u[k]+u[k]+v[k];
}
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<n;++i){
        ll u,v;
        cin>>u>>v;
        add_edge(u,v);
    }
    dfs(1);
    cout<<s[1]<<endl;
    return 0;
}