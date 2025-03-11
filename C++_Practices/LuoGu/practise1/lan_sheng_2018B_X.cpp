#include "iostream"
using namespace std;
#define ll long long int
ll x,y;
ll fuck(ll x1,ll y1){
    ll dis=0;
    for(int i=1;;++i){
        if(i&1) {
            for(int j=1;j<=i;++j) {
                x1--;
                dis++;
                if (x == x1 && y == y1) return dis;
            }
            for(int j=1;j<=i;++j) {
                y1++;
                dis++;
                if (x == x1 && y == y1) return dis;
            }
        }
        else{
            for(int j=1;j<=i;++j) {
                x1++;
                dis++;
                if (x == x1 && y == y1) return dis;
            }
            for(int j=1;j<=i;++j) {
                y1--;
                dis++;
                if (x == x1 && y == y1) return dis;
            }
        }
    }
}
int main(){
    cin>>x>>y;
    cout<<fuck(0,0);
}