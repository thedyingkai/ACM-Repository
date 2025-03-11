#include "iostream"
using namespace std;
int type,a,b,c,d;
int main(){
    cin>> type>>a>>b>>c>>d;
    if(type ==0) cout<<a+b<<endl;
    if(type==1) cout << max(a-c,0)+max(b-d,0);
    return 0;
}