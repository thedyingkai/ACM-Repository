#include "iostream"
using namespace std;
int n,m;
int temp,cnt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        if(cnt==0){
            temp=m;
            cnt++;
        }
        if(temp==m) cnt++;
        if(temp!=m) cnt--;
    }
    printf("%d",temp);
    return 0;
}