#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    long long sum=1;
    ios::sync_with_stdio(false);
    cin>>a;
    for(int i=1; i<=a; i++){
        sum*=i;
        while(sum%10==0) sum/=10;
        sum%=1000000000;
    }
    cout<<sum%10;
    return 0;
}