#include "iostream"
using namespace std;
int n,a[500005],b[500005];
void Merge(int start, int mid, int end){
    int i = start, j=mid+1, k = start;
    while(i!=mid+1 && j!=end+1) {           //将i,j两段从头开始扫描
        if(a[i] > a[j]) b[k++] = a[j++];    //如果段i首项大于段j首项，将段j首项加入b数组中
        else b[k++] = a[i++];               //否则，将段i首项加入b数组中
    }
    while(i != mid+1) b[k++] = a[i++];      //如果i,j段不等长，把没放完的长段剩余内容全部存进b数组
    while(j != end+1) b[k++] = a[j++];
    for(i=start; i<=end; i++) a[i] = b[i];
}
void MergeSort(int start, int end) {
    int mid;
    if(start < end) {
        mid = start + (end-start) / 2;       //向下递归，切割成单元
        MergeSort(start, mid);
        MergeSort(mid+1, end);
        Merge(start, mid, end);              //向回归并
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    MergeSort(0, n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}