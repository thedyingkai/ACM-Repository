#include <algorithm>
#include "iostream"
using namespace std;
int x,n;
int a[6];
int b[6]={0};
int main(){
    cin>> x>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++) scanf("%d",&a[j]);
        sort(a,a+5);
        bool s=false;
        for(int j=4;j>=0;j--) {
            if (x >= a[j] && !s) {
                b[a[j]]++;
                x-=a[j];
                s = true;
            }
        }
    }
    for(int i=1;i<6;i++){
        cout << b[i];
        if(i!=5) cout<< " ";
        else cout << endl;
    }
    cout << x;
    return 0;
}