#include "iostream"
using namespace std;
int t,n;
char a[100086];

int main (){
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a;
        int sum=0;
        for(int i=0;i<n;i++) if(a[i]!='0'&&i!=n-1) sum+=a[i]-'0'+1;
        cout << a[n-1]-'0'+sum <<endl;
    }
    return 0;
}