#include <iostream>
#include <algorithm>
using namespace std;
bool f(int q,int n,int m,int x[]){
    int last=0;
    for(int i=1;i<m;i++){
        int crt=last+1;
        while(crt<n&&x[crt]-x[last]<q) crt++;
        if(crt==n) return false;
        last=crt;
    }
    return true;
}
int main(){
    int n,m;                 //输入
    cin >> n >> m;
    int x[100086];
    for(int i=0;i<n;i++) cin >> x[i];
    int lb=0,ub=x[n-1];
    sort(x,x+n);     //排序
    while(ub-lb>1){
        int mid=(lb+ub)/2;
        if(f(mid,n,m,x)) lb=mid;
        else ub=mid;
    }
    cout << lb << endl;
    return 0;
}