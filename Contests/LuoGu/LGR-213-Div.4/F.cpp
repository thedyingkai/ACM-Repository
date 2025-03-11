#include "iostream"
using namespace std;
int n,m,x[51][51],s[51]={0},ma=-1,mm,maa=-1,mmm,sum=0;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin>>x[i][j];
        s[j]+=x[i][j];
    }
    for(int i=0;i<m;i++) if(s[i]>=ma){
        ma=s[i];
        mm=i;
    }
    for(int i=0;i<n;i++)if(x[i][mm]>maa){
        maa=x[i][mm];
        mmm=i;
    }
    cout<<x[mmm][mm]<<' ';
    for(int i=0;i<n;i++) if(x[i][mm]==x[mmm][mm]) sum++;
    cout<<sum;
}