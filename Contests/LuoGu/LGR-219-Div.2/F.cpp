#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long sum=0;
        vector<int> a(n+1),b(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i],sum+=b[i];
        vector<int> max_a(n+2);
        max_a[n]=a[n];
        for(int i=n-1;i>=1;i--) max_a[i]=max(a[i],max_a[i+1]);
        long long L=0,R=sum*(long long)max_a[1];
        while(L<=R){
            long long mid=L+R>>1;
            if([&]()->bool{
                long long s=0,c=0;
                for(int i=1;i<=n;i++){
                    s+=b[i];
                    if(a[i]==max_a[i]){
                        c+=s*a[i];
                        s=0;
                    }
                    if(c>=mid) c-=mid;
                    else{
                        long long need=mid-c;
                        long long m=ceil(need/a[i]);
                        if(m>s) return 0;
                        s-=m;
                        c=m*a[i]-need;
                    }
                }
                return 1;
            }()) L=mid+1;
            else R=mid-1;
        }
        cout<<L<<endl;
    }
}