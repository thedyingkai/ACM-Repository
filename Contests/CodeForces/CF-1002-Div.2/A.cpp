#include "iostream"
#include "vector"
#include "set"
using namespace std;
bool judge(int n,vector<int>& a,vector<int>& b) {
    int n1,n2;
    set<int> st;
    for(int i=0;i<n;++i) st.insert(a[i]);
    n1=st.size();
    st.clear();
    for(int i=0;i<n;++i) st.insert(b[i]);
    n2=st.size();
    return n1*n2>=3;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        if(judge(n,a,b)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}