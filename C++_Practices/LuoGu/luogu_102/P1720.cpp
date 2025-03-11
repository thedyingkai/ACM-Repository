#include "iostream"
#include "cmath"
using namespace std;
int main(){
    int n;
    double a=1,b=1;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        a*=0.5+sqrt(5)/2;
        b*=0.5-sqrt(5)/2;
    }
    printf("%.2f",(a-b)/sqrt(5));
}