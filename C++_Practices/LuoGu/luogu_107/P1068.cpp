#include "iostream"
#include "algorithm"
using namespace std;
int n,m,cnt=0;
struct stt{
    int k;
    int s;
}st[10002];
bool cmp(stt x,stt y){
    if(x.s>y.s||(x.s==y.s&&x.k<y.k)) return 1;
    else return 0;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>st[i].k>>st[i].s;
    sort(st,st+n,cmp);
    int qq=m*3/2-1;
    for(int i=0;i<n;i++) if(st[i].s>=st[qq].s) cnt++;
    cout<<st[qq].s<<' '<<cnt<<endl;
    for(int i=0;i<n;i++) if(st[i].s>=st[qq].s) cout<<st[i].k<<' '<<st[i].s<<endl;
}