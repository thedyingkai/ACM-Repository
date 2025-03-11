#include "iostream"
#include "cstring"
using namespace std;
char x[100086];
int a=0,b=0;
int main(){
    cin>>x;
    int dd=0;
    int n=strlen(x);
    for(int i=0;i<n;i++){
        if(x[i]=='X'){
            if(dd){
                cout<<-1;
                return 0;
            }
            a=a*10+2;
            b=b*10+1;
        }
        else if(x[i]=='Y'){
            if(dd){
                cout<<-1;
                return 0;
            }
            a=a*10+1;
            b=b*10+2;
        }
        else if(x[i]=='Z'){
            a=a*10+1;
            b=b*10+1;
            dd=1;
        }
    }
    printf("%d\n",a);
    printf("%d",b);
}
