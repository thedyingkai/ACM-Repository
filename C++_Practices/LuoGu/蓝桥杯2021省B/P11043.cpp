#include<bits/stdc++.h>
using namespace std;
int n,x,b[11],t=10e6;
string o;
int main(){
    cin>>n;
    while(cin>>o){
        if(o=="add"){
            cin>>x;
            b[0]++;
        }
        if(o=="sync"){
            cin>>x;
            b[x]++;
        }
        if(o=="query"){
            t=10e6;
            for(int i=1;i<n;i++) t=min(t,b[i]);
            cout<<t<<endl;
        }
    }
    return 0;
}