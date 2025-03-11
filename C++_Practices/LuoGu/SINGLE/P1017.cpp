#include"iostream"
using namespace std;
int n,r,m[100086],i=0;
int main(){
    cin>>n>>r;
    cout<<n<<"=";
    while(n!=0){
        m[i]=n%r;
        if(m[i]<0){m[i]-=r;n+=r;}
        if(m[i]>=10) m[i]='A'+m[i]-10;
        else m[i]+='0';
        n/=r;
        i++;
    }
    while(i--) printf("%c",m[i]);
    cout<<"(base"<<r<<")";
}