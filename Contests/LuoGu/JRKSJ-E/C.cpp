//
// Created by ASUS on 2025/2/9.
//
#include<iostream>
#include<vector>
using namespace std;
struct I{
    int l,r;
};
bool cfI(vector<I>& i,int l,int r){
    vector<bool>c(r,0);
    for(const auto& in:i) for(int j=max(in.l,l);j<min(in.r,r);++j) c[j]=1;
    for(int j=l;j<r;++j) if(!c[j]) return 0;
    return 1;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<I> i,o(m);
    vector<int> d;
    for(int z=0;z<m;++z){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            cin>>l>>r;
            o[z]={l,r};
            i.push_back({l,r});
        }
        else if(op==2){
            int t;
            cin>>t;
            d.push_back(t-1);
        }
        else if(op==3){
            int l,r;
            cin>>l>>r;
            bool p=cfI(i,l,r);
            cout<<(p?'Y':'N')<<endl;
        }
        for(auto it=d.begin();it!=d.end();){
            if(*it<i.size()){
                i.erase(i.begin()+*it);
                d.erase(it);
            }
            else ++it;
        }
    }
}
