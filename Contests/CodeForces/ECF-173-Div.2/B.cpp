#include "iostream"
using namespace std;
int T,n,d;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>d;
        cout<<"1";
        if(d%3==0||n>=3) cout<<" 3";
        if(d==5) cout<<" 5";
        if(d==7||n>=3) cout<<" 7";
        if(d==9||n>=6||(d%3==0&&n>=3)) cout<<" 9";
        cout<<endl;
    }
}