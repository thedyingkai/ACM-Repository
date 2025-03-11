#include <iostream>
#include <vector>
using namespace std;
int n,num[21],tar;
int f(){
    int sum=0;
    for(int i=0;i<n;i++) sum+=num[i];
    if(abs(tar)>sum||(sum+tar)%2!=0) return 0;
    int ss=(sum+tar)/2;
    vector<int> dp(ss+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++) for(int j=ss;j>=num[i];j--) dp[j]+=dp[j-num[i]];
    return dp[ss];
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];
    cin>>tar;
    cout<<f()<<endl;
}