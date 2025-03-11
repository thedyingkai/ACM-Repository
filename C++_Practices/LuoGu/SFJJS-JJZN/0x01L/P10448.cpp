#include "iostream"
#include "vector"
using namespace std;
int n,m;
vector<int> num;
void f(int x){
    if(num.size()>m||num.size()+n-x+1<m) return;
    if(x==n+1){
        for(int i=0;i<num.size();i++) cout<<num[i]<<' ';
        cout<<endl;
        return;
    }
    num.push_back(x);
    f(x+1);
    num.pop_back();
    f(x+1);
}
int main(){
    cin>>n>>m;
    f(1);
}