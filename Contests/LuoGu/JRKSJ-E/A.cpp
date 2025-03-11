//
// Created by ASUS on 2025/2/9.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sim(int c,int ml,bool mx,const vector<vector<int>>& g,int mv){
    if(ml==0) return mv;
    int bv=(mx?-1:1e9);
    for(int n:g[c]){
        int nmv=max(mv,n),r=sim(n,ml-1,!mx,g,nmv);
        if(mx)bv=max(bv,r);
        else bv=min(bv,r);
    }
    return bv;
}
vector<int> sol(int n,int m,int q,vector<pair<int,int>>& e){
    vector<vector<int>> g(n+1);
    for(const auto& ed:e){
        int u=ed.first,v=ed.second;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> rs;
    while(q--){
        int x,k;
        cin>>x>>k;
        int r=sim(x,k,true,g,0);
        rs.push_back(r);
    }
    return rs;
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<int,int>> e(m);
    for(auto& ed:e)cin>>ed.first>>ed.second;
    vector<int> rs=sol(n,m,q,e);
    for(int r:rs)cout<<r<<endl;
}