#include "iostream"
using namespace std;
int main(){
    int n,a[101],res=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<0<<' ';
    for(int i=1;i<n;i++){
        res=0;
        for(int j=0;j<i;j++) if(a[i]>a[j]) res++;
        cout<<res<<' ';
    }
}