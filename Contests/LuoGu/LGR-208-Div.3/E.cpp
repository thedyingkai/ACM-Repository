#include "iostream"
#include "algorithm"
using namespace std;
int main(){
        int n[100086];
        int i;
        for(i=0;i<100;i++){
            scanf("%d",&n[i]);
            if(n[i]==-1) break;
        }
        sort(n,n+i);
        int sum=1,res=n[0],mm=1;
        for(int j=1;j<i;j++){
            if(n[j]==n[j-1]){
                sum++;
                mm=max(sum,mm);
            }
            else{
                mm=max(sum,mm);
                sum=1;
            }
        }
        cout<<mm;
}