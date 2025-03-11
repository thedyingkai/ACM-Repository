#include "iostream"
using namespace std;
long long x,c,k;
int m=10000;
int main(){
    cin>>x>>c>>k;
    k--;
    while(k--){
        x=((x%m*x%m)%m+c%m)%m;
    }
    cout<<x;
}