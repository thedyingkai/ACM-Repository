#include "iostream"
using namespace std;
int x[10086],n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) if(x[i]<=15) cout<<x[i]<<' ';
    for(int i=0;i<n;i++) if(x[i]>15) cout<<x[i]<<' ';
}