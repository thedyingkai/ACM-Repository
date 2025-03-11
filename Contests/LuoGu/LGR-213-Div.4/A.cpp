#include "iostream"
using namespace std;
int a,b;
int main(){
    cin>>a>>b;
    if(a%10<=b) cout<<b-a%10;
    else cout<<b-a%10+10;
}