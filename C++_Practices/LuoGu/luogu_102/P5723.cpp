#include <cstring>
#include "iostream"
using namespace std;
int l,p[100086]={0},cnt=0;
bool ip[100086];
int main(){
    cin>>l;
    ip[1]=false;
    memset(ip,1,sizeof(ip));
    for(int i=2;i<=l;i++){
        if(ip[i]==1) p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<=l;j++){
            ip[i*p[j]]=0;
            if(i%p[j]==0) break;
        }
    }
    int sum=0,fuck=0;
    for(int i=1;i<cnt;i++) if(sum+p[i]<=l){
            sum+=p[i];
            fuck++;
            cout<<p[i]<<endl;
    }
    cout<<fuck<<endl;
}