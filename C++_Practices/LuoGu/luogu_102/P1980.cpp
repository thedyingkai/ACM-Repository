#include<iostream>
using namespace std;
long long n,i,x,b,c,t=0;
int main(){
    cin>>n>>x;
    for(i=1;i<=n;i++){
        b=i;
        while(b){
            c=b%10;
            b=b/10;
            if(c==x) t++;
        }
    }
    cout<<t<<endl;
    return 0;
}