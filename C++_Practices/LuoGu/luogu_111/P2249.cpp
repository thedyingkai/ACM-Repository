#include <iostream>
#include "algorithm"
using namespace std;
int n,m,a[1000086],x;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i+1]);
    for(int i=0;i<m;i++) {
        scanf("%d",&x);
        int ans=lower_bound(a+1,a+n+1,x)-a;//二分搜，注意-a
        if(x!=a[ans]) printf("-1 ");//没有，输出-1
        else printf("%d ",ans);
    }
    return 0;
}
/*STL 自带的二分函数—— upper_bound 和 lower_bound。
这两个函数的作用是二分查找一个数在数组中出现的位置。
区别是 upper 返回第一个大于搜索数的位置，而 lower 是第一个大于等于的数的位置。
函数的用法：lower_bound(a.begin(),a.end(),x) 返回第一个大于等于x的数的地址。
而由于是地址，在最后要a（也就是减去地址）。
*/