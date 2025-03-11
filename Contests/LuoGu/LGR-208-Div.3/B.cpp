#include "iostream"
using namespace std;
int t,n,k;
int a[100086];
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long int max=-1,sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>max) max=a[i];
            sum+=a[i];
        }
    }
    return 0;
}