#include<iostream>
using namespace std;
int T,n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n==1||n==3){
            cout<<"-1\n";
            continue;
        }
        if(n%2){
            for(int i=5;i<=n;i++) cout<<"3";
            cout<<"6366\n";
        }
        else{
            for(int i=3;i<=n;i++) cout<<"3";
            cout<<"66\n";
        }
    }
    return 0;
}