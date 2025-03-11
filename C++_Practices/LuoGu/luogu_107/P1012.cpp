#include "iostream"
#include "algorithm"
using namespace std;
int n;
string x[100086];
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i];
    sort(x,x+n,[](string a,string b){return a+b>b+a;});
    for(int i=0;i<n;i++) cout<<x[i];
}