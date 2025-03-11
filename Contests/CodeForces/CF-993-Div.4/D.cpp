#include <algorithm>
#include "iostream"
#include "cstring"
using namespace std;
int n,nn;
int main(){
    cin>>n;
    while(n--){
        cin>>nn;
        int a[200005],b[200005];
        int q,num=0,max=-1;
        for(int i=1;i<=nn;++i){
            cin>>q;
            if(a[q]==0) ++num;
            a[q]++;
            if(a[q]>max){
                max=a[q];
            }

        }
        for(int i=0;i<nn/num;i++){
            for(int j=1;j<=nn;j++) if(a[j]!=) printf("%d ",j);
            if(i!=0) for(int j=1;j<=nn;j++) if(a[j]==0) printf("%d ",j);
        }
        if(nn%num!=0) for(int i=1;i<=nn%num;){
            for(int j=1;j<=nn;j++) if(a[j]==0){
                printf("%d ",j);
                i++;
            }
        }
        cout<<endl;
    }
}