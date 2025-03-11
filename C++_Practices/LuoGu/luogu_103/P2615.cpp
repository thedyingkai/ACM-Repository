#include"iostream"
using namespace std;
int n,m[40][40]={0};
int main(){
    cin>>n;
    int l=0,r=n/2;
    m[l][r]=1;
    for(int i=2;i<=n*n;i++){
        if(l==0&&r!=n-1){
            l=n-1;
            m[l][++r]=i;
        }
        else if(l!=0&r==n-1){
            r=0;
            m[--l][r]=i;
        }
        else if(l==0&&r==n-1) m[++l][r]=i;
        else if(l!=0&&r!=n-1){
            if(m[l-1][r+1]==0) m[--l][++r]=i;
            else m[++l][r]=i;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<m[i][j]<<' ';
        cout<<endl;
    }
}