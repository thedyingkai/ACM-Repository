#include <iostream>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    char x[100][100];
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) x[i][j]='.';
    if(2*m==n+1){
        for(int i=0;i<n;++i){
            for(int j=0;j<=i&&j<m;++j) x[i][j]='#';
            for(int j=0;j<=n-i-1&&j<m;++j) x[n-i-1][j]='#';
        }
    }
    else if(n==k){
        for(int i=0;i<n;++i) for(int j=0;j<m;++j) x[i][j]='#';
        for(int j=m-1;j>=m-n/2;--j) for(int i=0;i<(n-(m-j))/2;++i){
            x[i][j]='.';
            x[n-1-i][j]='.';
        }
    }
    else{
        int mid=n/2;
        int t=mid-(k/2);
        int re=m-((n+1)/2);
        for(int r=0;r<n;++r) for(int c=max(0,re);c<m-abs(r-mid);++c) x[r][c]='#';
        for(int r=t;r<t+k;++r) for(int c=0;c<re;++c) x[r][c]='#';
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) cout<<x[i][j];
        cout<<endl;
    }
    return 0;
}