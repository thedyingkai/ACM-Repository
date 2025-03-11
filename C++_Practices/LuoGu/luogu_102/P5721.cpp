#include<iostream>
using namespace std;
int main(){
    int n,t=1;
    cin>>n;
    int a=n;
    for(int i=0;i<n;i++,a--){
        for(int j=0;j<a;j++){
            printf("%02d",t);
            t++;
        }
        cout<<endl;
    }
    return 0;
}