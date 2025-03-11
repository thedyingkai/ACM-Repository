#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
    ll mx;
    int i;
};
struct ST{
    int n;
    vector<st> tr;
    vector<ll> la;
    ST(int n):n(n){
        tr.resize(4*n);
        la.assign(4*n,0);
    }
    void bd(int i,int l,int r){
        if(l==r){
            tr[i].mx=l;
            tr[i].i=l;
            return;
        }
        int mid=(l+r)/2;
        bd(i*2,l,mid);
        bd(i*2+1,mid+1,r);
        mr(i);
    }
    void mr(int i){
        if(tr[i*2].mx>tr[i*2+1].mx) tr[i]=tr[i*2];
        else if(tr[i*2].mx<tr[i*2+1].mx) tr[i]=tr[i*2+1];
        else tr[i]=(tr[i*2].i<tr[i*2+1].i?tr[i * 2]:tr[i*2+1]);
    }
    void ap(int i,int l,int r,ll val){
        tr[i].mx+=val;
        la[i]+=val;
    }
    void pdd(int i,int l,int r){
        if(la[i]!=0){
            int mid=(l+r)/2;
            ap(i*2,l,mid,la[i]);
            ap(i*2+1,mid+1,r,la[i]);
            la[i]=0;
        }
    }
    void ud(int i,int l,int r,int ql,int qr,ll val){
        if(ql>r||qr<l) return;
        if(ql<=l&&r<=qr){
            ap(i,l,r,val);
            return;
        }
        pdd(i,l,r);
        int mid=(l+r)/2;
        ud(i*2,l,mid,ql,qr,val);
        ud(i*2+1,mid+1,r,ql,qr,val);
        mr(i);
    }
    st qrr(int i,int l,int r,int ql,int qr){
        if(ql>r||qr<l) return {-LLONG_MAX,-1};
        if(ql<=l&&r<=qr) return tr[i];
        pdd(i,l,r);
        int mid=(l+r)/2;
        st lst=qrr(i*2,l,mid,ql,qr);
        st rst=qrr(i*2+1,mid+1,r,ql,qr);
        if(lst.mx>rst.mx) return lst;
        else if(lst.mx<rst.mx) return rst;
        else{
            if(lst.i==-1) return rst;
            if(rst.i==-1) return lst;
            return (lst.i<rst.i?lst:rst);
        }
    }
    void ud(int ql,int qr,ll val){
        if(ql>qr) return;
        ud(1,1,n,ql,qr,val);
    }
    st qrrr(int ql,int qr){return qrr(1,1,n,ql,qr);}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<int> first(n+1,-1),last(n+1,-1);
        for(int i=1;i<=n;i++){
            int v=a[i];
            if(first[v]==-1) first[v]=i;
            last[v]=i;
        }
        vector<pair<int,int>> ni;
        for(int v=1;v<=n;v++) if(first[v]!=-1) ni.push_back({first[v],last[v]});
        sort(ni.begin(),ni.end(),[](const pair<int, int> &p1,const pair<int, int> &p2){return p1.second < p2.second;});
        int ttt=ni.size(),ptr=0,cs=0;
        ST seg(n);
        seg.bd(1,1,n);
        ll F=0;
        int bl=0,br=0,bln=0;
        for(int r=1;r<=n;r++){
            while(ptr<ttt&&ni[ptr].second==r){
                int pos=ni[ptr].first;
                if(pos<n) seg.ud(pos+1,n,-1);
                cs++;
                ptr++;
            }
            st res=seg.qrrr(1,r);
            ll cc=cs+res.mx-(r+1LL);
            int len=r-res.i+1;
            if(cc>F||(cc==F&&len>bln)) F=cc,bln=len,bl=res.i,br=r;
        }
        if(F<0||(F==0&&bln==0)) cout<<0<<endl;
        else cout<<bl<<" "<<br<<endl;
    }
}