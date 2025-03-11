#include "iostream"
#include "algorithm"
using namespace std;
int t,a[3],d;
int main(){
    cin >> t;
    while(t--){
        cin >> a[0] >> a[1] >> a[2] >> d;
        sort(a,a+3);
        if(d<=a[0]+a[1]+a[2]-3&&max(0,a[2]-a[1]-a[0]-1)<=d) cout<< "YES"<<endl;
        else cout <<"NO"<<endl;
    }
    return 0;
}