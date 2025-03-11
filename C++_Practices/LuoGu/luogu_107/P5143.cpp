#include "iostream"
#include "algorithm"
#include "cmath"
using namespace std;
int n;
double sum=0.0;
struct str{
    int x;
    int y;
    int z;
}p[50005];
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y>>p[i].z;
    sort(p,p+n,[](str a,str b){return a.z>b.z;});
    for(int i=1;i<n;i++) sum+=sqrt(pow(p[i].x-p[i-1].x,2)+pow(p[i].y-p[i-1].y,2)+pow(p[i].z-p[i-1].z,2));
    printf("%.3f",sum);
}