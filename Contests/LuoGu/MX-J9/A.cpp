#include "iostream"
using namespace std;
int a,b,c,d;
int main(){
    for(int i=0;i<3;i++){
        int q;
        cin>>q;
        if(q>=85) a++;
        else if(q>=45) b++;
        else if(q>=25) c++;
        else if(q!=0) d++;
    }
    if((b==1&&c==1&&d==1)||(a==1&&b==1&&c==1)||(a==2&&(b==1||c==1))||(a==3)) cout<<"Yes";
    else cout<<"No";
}