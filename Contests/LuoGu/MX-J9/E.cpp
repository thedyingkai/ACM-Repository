#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
int n,res=0;
vector<int> p;
vector<int> a;
bool isValid(){
    for(int i=0;i<n;++i) if(a[i]!=p[i]&&a[p[i]-1]!=i+1) return 0;
    return 1;
}
int main(){
    cin>>n;
    p.resize(n);
    a.resize(n);
    for(int i=0; i<n;++i) cin>>p[i];
    for(int i=0; i<n;++i) a[i]=i+1;
    do{
        if(isValid()) res=(res+1)%MOD;
    }while(next_permutation(a.begin(),a.end()));
    cout<<res;
}