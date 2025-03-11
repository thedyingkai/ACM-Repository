#include "iostream"
using namespace std;
int a[4],b[4],res=0;
int main(){
    for(int i=0;i<4;i++) cin>>a[i];
    for(int i=0;i<4;i++) cin>>b[i];
    for(int i=0;i<4;i++) {
        int c[4]={0};
        for(int j=1;j<4;j++){
            if(a[i]>a[(i+j)%4]) c[j]++;
            if(b[i]<b[(i+j)%4]) c[j]++;
        }
        for(int j=1;j<4;j++) if(c[j]==2) res++;
    }
    cout<<res;
}
