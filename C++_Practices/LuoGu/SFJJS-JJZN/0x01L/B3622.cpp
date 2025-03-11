#include <iostream>
#include <string>
using namespace std;
int n;
void f(int x,string s){
    if(x==n+1){cout<<s<<endl;return;}
    f(x+1,s+'N');
    f(x+1,s+'Y');
}
int main(){
    cin>>n;
    f(1,"");
}