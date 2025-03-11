#include "iostream"
using namespace std;
int n,a[100086];
int main(){
    cin>>n;
    int res=0;
    int m=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0){
            if(a[i]-1==a[i-1]){
                res++;
                m=max(m,res);
            }
            else{
                res=0;
            }
        }
    }
    if(m>=0) cout<<m+1;
    else cout<<1;
}