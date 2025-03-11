#include "iostream"
using namespace std;
int main(){
    int n,mx=-1,mi=11;
    double sum=0;
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        sum+=a;
        mx=max(a,mx);
        mi=min(a,mi);
    }
    printf("%.2f",(sum-mi-mx)/(n-2));
}