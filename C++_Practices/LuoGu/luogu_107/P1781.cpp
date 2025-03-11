#include "iostream"
#include "cstring"
#include "algorithm"
using namespace std;
struct ssb{
    int n;
    string a;
    int l;
}ss[21];
bool cmp(ssb x,ssb y){
    if(x.l>y.l) return 1;
    if(x.l==y.l&&x.a>y.a) return 1;
    return 0;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ss[i].a;
        ss[i].n=i+1;
        ss[i].l=ss[i].a.size();
    }
    sort(ss,ss+n,cmp);
    cout<<ss[0].n<<endl<<ss[0].a;
}