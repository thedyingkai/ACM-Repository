#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool isValidPath(int s,int t,const set<pair<int, int>>&edges){
    set<pair<int, int>> pathEdges;
    while(s!=t){
        if(s>t) swap(s,t);
        pathEdges.insert({s,s+1});
        s++;
    }
    for(const auto&edge:pathEdges) if(edges.find(edge)==edges.end()) return false;
    return true;
}
bool solve(int n,int m,vector<pair<int,int>>&pairs){
    set<pair<int,int>> treeEdges;
    if(n==3){
        treeEdges={{1,2},{2,3}};
        for(const auto&p:pairs) if(!isValidPath(p.first, p.second, treeEdges)) return false;
        return true;
    }
    if (n==2){
        treeEdges={{1,2}};
        for(const auto&p:pairs) if(!isValidPath(p.first,p.second,treeEdges)) return false;
        return true;
    }
    if(n==1) return m==0;
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>pairs(m);
    for(int i=0;i<m;i++) cin>>pairs[i].first>>pairs[i].second;
    if(solve(n,m,pairs)){
        cout<<"Yes"<<endl;
        if (n==3){
            cout<<"1 2"<<endl;
            cout<<"2 3"<<endl;
        }
        else if(n==2) cout<<"1 2"<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}