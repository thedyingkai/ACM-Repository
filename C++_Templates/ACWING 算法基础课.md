# 第一章 基础算法
## 排序
### 快速排序
```cpp
CI N=1e6+10;
int n,q[N];
void quick_sort(int q[],int l,int r){
    if(l>=r) return;
    int x=q[l],i=l-1,j=r+1;
    while(i<j){
        do i++;while(q[i]<x);
        do j++;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}
```
### 归并排序
```cpp
CI N=100010;
int n,q[N],tmp[N];
void merge_sort(int q[],int l,int r){
    if(l>=r) return;
    int mid=l+r>>1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);
    int k=0,i=1,j=mid+1;
    while(l<=mid&&j<=r) if(q[i]<=q[j]) tmp[k++]=q[i++];
    else tmp[k++]=q[j++];
    while(i<=mid) tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];
    for(int i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
}
```
## 二分
### 整数二分
### 实数二分
## 高精度
## 前缀和
## 差分
## 位运算
## 离散化
# 第二章 数据结构
## 链表与临接表
### 单链表
```cpp
CI N=100010;int head,e[N],ne[N],idx;
void init(){head=-1,idx=0;}
void add_to_head(int x){e[idx]=x,ne[idx]=head,head=idx++;}
void add(int k,int x){e[idx]=x,ne[idx]=ne[k-1],ne[k-1]=idx=+;}
void remove(int k){
    if(!k) {head=ne[head];return;}
    ne[k-1]=ne[ne[k-1]];
}
```
### 双链表
```cpp
CI N=100010;
int m,e[N],l[N],r[N],idx;
void init(){r[0]=1,l[1]=0,idx=2;}
void addr(int k,int x){e[idx]=x,r[idx]=r[k],l[idx]=k,l[r[k]]=idx,r[k]=idx;}// 在 k 右边插入
void addl(int k,int x){addr(l[k],x);}
void remove(int k){r[l[k]]=r[k],l[r[k]]=l[k];}
```
## 栈与队列
### 栈
```cpp
CI n=100010;
int stk[N],tt;
stk[++tt]=x; // insert
tt--; // pop
if(tt>0) // unempty
else // empty
stk[tt] // top
```
### 队列
```cpp
CI n=100010;
int q[N],hh,tt=-1;
q[++tt]=x; // insert
hh++; // pop
if(hh<=tt) // unempty
else // empty
q[hh] // top
q[tt] // end
```
### 单调栈
```cpp
CI N=100010;
int n,stk[N],tt;
void solve(){
    for(int i=0;i<n;i++){
        int x;cin>>x;
        while(tt&&ststk[tt]>=x) tt--;
        if(tt) cout<<stdk[tt]<<endl;
        else cout<<-1<<endl;
        stk[++tt]=x;
    }
}
```
### 单调队列
```cpp
CI N=1000010;
int n,k,a[N],q[N];
void min(){
    hh=0=,tt=-1;
    for(int i=0;i<n;i++){
        if(hh<=tt&&i-k+1>q[hh]) hh++;
        while(hh<=tt&&a[q[tt]]>=a[i]) tt--;
        q[+tt]=i;
        cout<<a[q[hh]];
    }
}
void max(){
    hh=0=,tt=-1;
    for(int i=0;i<n;i++){
        if(hh<=tt&&i-k+1>q[hh]) hh++;
        while(hh<=tt&&a[q[tt]]<=a[i]) tt--;
        q[+tt]=i;
        cout<<a[q[hh]];
    }
}
```
## KMP
```cpp
CI N=1000006;
char s1[N]={0},s2[N]={0};
void KMP(){
    scanf("%s%s",s1+1,s2+1);
    int n=strlen(s1+1);
    int m=strlen(s2+1);
    int nxt[N]={0};
    for(int i=2,j=0;i<=m;i++){
        while(j&&s2[i]!=s2[j+1]) j=nxt[j];
        if(s2[i]==s2[j+1]) j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=n;i++){
        while(j&&s1[i]!=s2[j+1]) j=nxt[j];
        if(s1[i]==s2[j+1]) j++;
        if(j==m){
            cout<<i-m+1<<endl;
            j=nxt[j];
        }
    }
}
```


