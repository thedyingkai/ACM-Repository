#include<iostream>
using namespace std;
int main(){
    int a[13],m=0,n=0;
    for(int i=1;i<=12;i++)cin>>a[i];
    for(int i=1;i<=12;i++){
        m=((n+300-a[i])/100)*100+m;
        n=(n+300-a[i])-(n+300-a[i])/100*100;
        if(n<0){
            cout<<-i;
            return 0;
        }
    }
    cout<<m*1.2+n<<endl;
}