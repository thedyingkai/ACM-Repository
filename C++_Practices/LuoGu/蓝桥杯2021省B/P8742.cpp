#include "iostream"
#include "bitset"
using namespace std;
int n,x[101];
bitset<100086> vis[101],res;
void dfs(int a,int s){
    if(a==n){
        if(s>0) res[s]=1;
        return;
    }
    if(vis[a][s]) return;
    dfs(a+1,s+x[a]);
    dfs(a+1,s);
    dfs(a+1,abs(s-x[a]));
    vis[a][s]=1;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i];
    dfs(0,0);
    cout<<res.count();
}