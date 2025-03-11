#include "iostream"
using namespace std;
int a=0,b=0,j=0;
bool p[100086];
char t;
int main(){
    while(1){
        scanf("%c",&t);
        if(t=='E') break;
        if(t=='W') p[j++]=1;
        if(t=='L') p[j++]=0;
    }
    for(int i=0;i<j;i++){
        if(p[i]) a++;
        else b++;
        if((abs(a-b)>=2&&(a>=11||b>=11))){
            cout<<a<<':'<<b<<endl;
            a=0;
            b=0;
        }
    }
    cout<<a<<":"<<b<<endl;
    a=0;
    b=0;
    cout<<endl;
    for(int i=0;i<j;i++){
        if(p[i]) a++;
        else b++;
        if((abs(a-b)>=2&&(a>=21||b>=21))){
            cout<<a<<':'<<b<<endl;
            a=0;
            b=0;
        }
    }
    cout<<a<<":"<<b<<endl;
}