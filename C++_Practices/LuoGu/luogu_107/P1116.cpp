#include "iostream"
using namespace std;
int n,a[100086],cnt=0;
void mm(int a[]){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                cnt++;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    mm(a);
    cout<<cnt;
}