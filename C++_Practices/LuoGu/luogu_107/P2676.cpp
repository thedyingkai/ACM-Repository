#include "iostream"
#include "algorithm"
using namespace std;
long long n,b,h[100086],s,e=0;
int main(){
    cin>>n>>b;
    for(long long i=0;i<n;i++) cin>>h[i];
    sort(h,h+n);
    int nn=n;
    while(1){
        s+=h[--nn];
        if(s>b) break;
    }
    cout<<n-nn;
}