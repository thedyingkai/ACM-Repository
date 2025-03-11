#include "iostream"
#include "algorithm"
using namespace std;
int l,n,m,x[100086];
bool f(int mid){
    int i,last=0,cnt=0;
    for(i=1;i<n+1;i++){
        if(x[i]-last<=mid) cnt++;
        else last=x[i];
    }
    if(l-last<=mid)cnt++;
    return cnt<=m;
}
int main(){
    cin>>l>>n>>m;
    int i=1;
    for(;i<=n;i++) cin>>x[i];
    int max=l,min=1;
    while (max>min){
        int mid=(min+max)/2;
        if(f(mid)) min=mid+1;
        else max=mid;
    }
    cout<<min<<endl;
    return 0;
}