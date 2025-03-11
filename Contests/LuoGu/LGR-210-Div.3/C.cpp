#include <bits/stdc++.h>
using namespace std;
string f(const string& s){
    string result;
    for(char c:s){
        while(!result.empty()&&result.back()<c) result.pop_back();
        result.push_back(c);
    }
    return result;
}
string cal(int n,int k,const string& s){
    vector<vector<string>> dp(n+1,vector<string>(k+1,string(n,'z')));
    dp[0][0]="";
    for(int i=1;i<=n;++i) for(int j=1;j<=k;++j) for(int l=0;l<i;++l){
        string sub=f(s.substr(l,i-l));
        dp[i][j]=min(dp[i][j],max(dp[l][j-1],sub));
    }
    return dp[n][k];
}
int main() {
    string s;
    int n,k;
    cin>>n>>k>>s;
    string res=cal(n,k,s);
    cout<<res;
    return 0;
}