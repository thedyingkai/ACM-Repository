#include "iostream"
using namespace std;
int a[1000086],b[1000086];
string s;
bool ff(){
    bool f=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='Z') f=1;
        if(f==1&&s[i]!='Z') return 1;
    }
    return 0;
}
int main(){
    cin>>s;
    if(ff()){
        cout<<"-1";
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='X'){
            a[i]=1;
            b[i]=0;
        }
        else if(s[i]=='Y'){
            a[i]=0;
            b[i]=1;
        }
        else if(s[i]=='Z'){
            a[i]=1;
            b[i]=1;
        }
    }
    for(int i=0;i<s.size();i++) cout<<a[i];
    cout<<endl;
    for(int i=0;i<s.size();i++) cout<<b[i];
    cout<<endl;
    return 0;
}