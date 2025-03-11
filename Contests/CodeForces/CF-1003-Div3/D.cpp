//
// Created by ASUS on 2025/2/9.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int t,n,m;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> a(n+1,vector<int>(m+1));
        vector<long long> b;
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long s=0;
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                s+=a[i][j];
                ans+=s;
            }
            b.push_back(s);
        }
        sort(b.begin(),b.end(),greater<>());
        long long tem=0;
        for (int i=0;i<n;i++){
            ans+=tem*m;
            tem+=b[i];
        }
        cout<<ans<<endl;
    }
}