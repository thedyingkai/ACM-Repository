#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int n,p;
int a[100086];
int sol(){
    int s=0,t=0,num=0;
    map<int,int> count;
    int res=n;
    while(1){
        while(t<n&&num<p){
            if(count[a[t]]==0) num++;
            count[a[t]]++;
            t++;
        }
        if(num<p) break;
        res = min(res,t-s);
        count[a[s]]--;
        if(count[a[s]]==0) num--;
        s++;
    }
    return res;
}
int main(){
    scanf("%d",&n);
    set<int> all;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        all.insert(a[i]);
    }
    p = all.size();
    cout << sol() << endl;
    return 0;
}