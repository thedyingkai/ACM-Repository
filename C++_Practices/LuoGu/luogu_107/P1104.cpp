#include "iostream"
#include "algorithm"
using namespace std;
int n;
struct st{
    int i;
    string s;
    int y;
    int m;
    int d;
}x[100086];
bool cmp(st a,st b){
    if(a.y!=b.y) return a.y<b.y;
    if(a.m!=b.m) return a.m<b.m;
    if(a.d!=b.d) return a.d<b.d;
    return a.i>b.i;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i].s>>x[i].y>>x[i].m>>x[i].d;
        x[i].i=i;
    }
    sort(x,x+n,cmp);
    for(int i=0;i<n;i++) cout<<x[i].s<<endl;
}