//
// Created by ASUS on 2025/2/9.
//
#include "iostream"
#include "algorithm"
using namespace std;
int t,n,m,k,flag;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        flag=0;
        if(n<m){
            swap(n,m);
            flag=1;
        }
        if(k>n||k<n-m){
            cout<<"-1\n";
            continue;
        }
        for(int i=0;i<k;i++) cout<<(0^flag);
        for(int i=0;i<n-k;i++) cout<<(1^flag)<<(0^flag);
        for(int i=0;i<m-n+k;i++) cout<<(1^flag);
        cout<<'\n';
    }
}