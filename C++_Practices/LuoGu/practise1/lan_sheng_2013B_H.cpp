#include "iostream"
using namespace std;
int main(){
    long long x,y,n,d;
    cin>>x;
    cin>>y;
    n=max(abs(x),abs(y)),d=2*n*(2*n+1);
    if(y>=0&&abs(x)<=y) cout<<d-3*n+x;
    else if(y<0&&y<x&&x<=-y) cout<<d+n-x;
    else if(x>=0&&abs(y)<=x) cout<<d-n-y;
    else if(x<0&&x<y&&y<=-x) cout<<d-5*n+y;
}