#include "iostream"
using namespace std;
int n;
int k,d,a[100086];

int main(){
    cin>> n;
    int fu=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(a[i]<=a[j]){
                fu++;
                break;
            }
        }
    }
    cout << n-fu;
    return 0;
}