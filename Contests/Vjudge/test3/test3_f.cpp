#include "iostream"
using namespace std;
int t,n;
char a[55];
char b[55][55];

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a;
        int f=0;
        for(int i=0;i<n;i++) if(a[i]=='2') f++;
        if(f<=2&&f!=0){
            cout << "NO"<<endl;
            continue;
        }
        else cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j) b[i][j]='X';
                else if(a[i]=='1'||a[j]=='1'){
                    b[i][j]='=';
                    b[j][i]='=';
                }
                else if(a[i]=='2') {
                    b[i][j]='+';
                    b[j][i]='-';
                    a[i]=0;
                }
                else if(a[j]=='2') {
                    b[i][j]='-';
                    b[j][i]='+';
                    a[j]=0;
                }
                else{
                    b[i][j]='=';
                    b[j][i]='=';
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout << b[i][j];
            cout << endl;
        }
    }
    return 0;
}