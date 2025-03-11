#include "iostream"
using namespace std;
int n,a[500005],b[500005];
long long sum=0;
void Merge(int start, int mid, int end){
    int i = start, j=mid+1, k = start;
    while(i!=mid+1 && j!=end+1) {
        if(a[i] > a[j]){
            sum+=mid-i+1;
            b[k++] = a[j++];
        }
        else b[k++] = a[i++];
    }
    while(i != mid+1) b[k++] = a[i++];
    while(j != end+1) b[k++] = a[j++];
    for(i=start; i<=end; i++) a[i] = b[i];
}
void MergeSort(int start, int end) {
    int mid;
    if(start < end) {
        mid = start + (end-start) / 2;
        MergeSort(start, mid);
        MergeSort(mid+1, end);
        Merge(start, mid, end);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    MergeSort(0, n-1);
    cout<<sum;
}