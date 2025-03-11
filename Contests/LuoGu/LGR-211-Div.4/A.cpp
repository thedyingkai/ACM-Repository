#include "iostream"
using namespace std;
int a,b,c,d,x,sum=0;
int main(){
    cin>>a>>b>>c>>d>>x;
    if(x>=a) sum+=b;
    if(x>=c) sum+=d;
    cout<<sum;
}