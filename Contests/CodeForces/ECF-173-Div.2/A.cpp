#include "iostream"
using namespace std;
int T;
long long x,sum=1;
int main(){
    cin>>T;
    while(T--){
        cin>>x;
        sum=1;
        while(x>3){
            x/=4;
            sum=2*sum;
        }
        cout<<sum<<endl;
    }
}