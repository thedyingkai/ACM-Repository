#include <iostream>
using namespace std;
int a,num;
int main(){
    cin>>a;
    while(a!=0){
        num=num*10+a%10;
        a/=10;
    }
    cout<<num;
    return 0;
}