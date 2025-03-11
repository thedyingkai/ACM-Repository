#include "iostream"
using namespace std;
int n;
int i=0;
int k,d,a;
int qq;
int maxx=-1e6;
int res;
int main(){
    cin>> n;
    while(n--){
        scanf("%d/%d/%d",&k,&d,&a);
        if(k-d>=10) qq=k*(k-d)+a;
        else{
            if(k>=d) qq=(k-d+1)*3+a;
            else qq=a*2;
        }
        if(qq>maxx) {
            maxx=qq;
            res=i+1;
        }
        i++;
    }
    cout << res;
    return 0;
}