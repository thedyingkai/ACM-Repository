
#include "iostream"
using namespace std;
int t,n;

int main(){
    cin >> t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++) cout << "(";
            for(int j=0;j<i+1;j++) cout << ")";
            for(int j=0;j<n-i-1;j++) cout << "()";
            cout <<endl;
        }
    }
    return 0;
}