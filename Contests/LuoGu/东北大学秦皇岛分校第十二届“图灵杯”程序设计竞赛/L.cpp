#include <iostream>
#include <vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int &x:a) cin>>x;
        for(int &x:b) cin>>x;
        int xorA=0,xorB=0;
        for (int i=0;i<n;++i){
            xorA^=a[i];
            xorB^=b[i];
        }
        int result=0;
        for(int bit=30;bit>=0;--bit){
            bool ff=0;
            for(int i=0;i<n&&!ff;++i) {
                if((a[i]&(1<<bit))&&(b[i]&(1<<bit))) ff=1;
            }
            if(ff&&(result|(1<<bit))<=min(xorA,xorB)) result|=(1<<bit);
        }
        cout<<result*2;
    }
}