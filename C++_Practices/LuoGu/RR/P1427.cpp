#include "iostream"
using namespace std;
int main(){
    int b[100086],i=0;
    while(1){
        int a,q;
        scanf("%d",&a);
        if(a==0) break;
        b[i]=a;
        i++;
    }
    while(--i) cout<<b[i]<<' ';
    cout<<b[0];
}