#include "iostream"
using namespace std;
int x,y;
char a[101][101],b;
int main(){
    cin>>x>>y;
    for(int i=1;i<=x;i++) for(int j=1;j<=y;j++){
        cin>>b;
        if(b=='*') a[i][j]='*';
        else a[i][j]='0';
    }
    for(int i=1;i<=x;i++) for(int j=1;j<=y;j++) if(a[i][j]=='*'){
        if(i!=1) if(a[i-1][j]!='*') a[i-1][j]++;
        if(i!=x) if(a[i+1][j]!='*') a[i+1][j]++;
        if(j!=1) if(a[i][j-1]!='*') a[i][j-1]++;
        if(j!=y) if(a[i][j+1]!='*') a[i][j+1]++;
        if(i!=1&&j!=1) if(a[i-1][j-1]!='*') a[i-1][j-1]++;
        if(i!=x&&j!=y) if(a[i+1][j+1]!='*') a[i+1][j+1]++;
        if(j!=1&&i!=x) if(a[i+1][j-1]!='*') a[i+1][j-1]++;
        if(j!=y&&i!=1) if(a[i-1][j+1]!='*') a[i-1][j+1]++;
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++) cout<<a[i][j];
        cout<<endl;
    }
}