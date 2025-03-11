#include "iostream"
using namespace std;
int main(){
    int n,a[1002]={0},i=1;
    cin>>n;
    while(n!=1){
        a[i++]=n;
        if(n%2==0) n/=2;
        else n=3*n+1;
    }
    a[i]=1;
    for(int j=i;j>=1;j--) cout<<a[j]<<' ';
}