#include "iostream"
using namespace std;
int n,x[1001][1001];
int main(){
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<=i;j++) cin>>x[i][j];
    for(int i=n-2;i>=0;i--) for(int j=0;j<=i;j++) x[i][j]+=max(x[i+1][j],x[i+1][j+1]);
    cout<<x[0][0];
}