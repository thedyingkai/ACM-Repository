#include<bits/stdc++.h>
using namespace std;
int n,x,sum;
int t[1000086];
int a[10086];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);    //读取同学的能力值
        t[x]++;                  //存每个能力值的人数
    }
    for(int i=1;i<1000086;i++){
        sum=0;
        for(int j=1;i*j<1000086;j++) sum+=t[i*j];   //求能力值能被i整除的人的个数
        a[sum]=i;
        /*由于i从小到大遍历，sum只会越来越小，故可以直接覆盖存储，
         *？？？你妈
         */
    }
    for(int i=n-1;i>=1;i--) a[i]=max(a[i],a[i+1]);  //后缀最大值
    for(int i=1;i<=n;i++) printf("%d\n",a[i]);//输出
}
/*后缀最大值，即取每个数的后面所有数的最大值，最后一位补全为-1
 *     例：34 73 90 48 82 35
 *处理后为：90 90 82 82 35 -1
 */