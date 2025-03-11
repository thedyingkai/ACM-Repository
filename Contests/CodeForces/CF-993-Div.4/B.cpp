#include "iostream"
#include "cstring"
using namespace std;
int n;
char a[1000];
int main(){
    cin>>n;
    while(n--){
        cin>>a;
        for(int i=strlen(a)-1;i>=0;i--){
            if(a[i]=='p') cout<<'q';
            if(a[i]=='q') cout<<'p';
            if(a[i]=='w') cout<<'w';
        }
        cout<<endl;
    }
}