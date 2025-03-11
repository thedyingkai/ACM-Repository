//
// Created by ASUS on 2025/2/9.
//
#include<iostream>
#include<vector>
using namespace std;
int pc(int x){
    int c=0;
    while(x){
        c+=x&1;
        x>>=1;
    }
    return c;
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<q;++i){
        int L,R;
        cin>>L>>R;
        int ms=0;
        for(int x=L;x<=R;++x){
            int cs=0;
            for(int j=0;j<n;++j) cs+=pc(a[j]+x);
            ms=max(ms,cs);
        }
        cout<<ms<<endl;
    }
}