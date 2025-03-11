//
// Created by ASUS on 2025/2/8.
//
#include "iostream"
#include "algorithm"
using namespace std;
int n,qq[300005];
struct st{
    int i;
    int p;
    int q;
}x[300005];
bool cmp(st a,st y){
    return a.q<y.q;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i].p;
        x[i].i=i+1;
    }
    for(int i=0;i<n;i++){
        cin>>x[i].q;
        qq[i]=x[i].q;
    }
    sort(x,x+n,cmp);
    for(int i=0;i<n;i++) cout<<qq[x[i].p-1]<<' ';
}