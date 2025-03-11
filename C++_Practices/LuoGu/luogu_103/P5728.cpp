//
// Created by ASUS on 2025/2/7.
//
# include <iostream>
using namespace std;
int n,a[1005][5],sum[1005],res=0;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        sum[i]=a[i][1]+a[i][2]+a[i][3];
    }
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(abs(a[i][1]-a[j][1])<=5&&abs(a[i][2]-a[j][2])<=5&&abs(a[i][3]-a[j][3])<=5&&abs(sum[i]-sum[j])<=10) res++;
    cout<<res;
}