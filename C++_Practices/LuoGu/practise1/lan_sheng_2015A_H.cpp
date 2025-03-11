#include "iostream"
using namespace std;
int n;
int main(){
    cin>>n;
    int sum=n,ll;
    while(n>3){
        ll=n%3;
        n/=3;
        sum+=n;
        n+=ll;
    }
    if(n==3) sum++;
    cout<< sum;
    return 0;
}