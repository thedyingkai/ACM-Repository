#include "iostream"
#include "algorithm"
using namespace std;
int n;
struct stud{
    int ch;
    int ma;
    int en;
    int n;
    int s;
}stu[100086];
bool cmp(stud x,stud y){
    if(x.s>y.s) return 1;
    else if(x.s<y.s) return 0;
    else{
        if(x.ch>y.ch) return 1;
        else if(x.ch<y.ch) return 0;
        else{
            if(x.n<y.n) return 1;
            else if(x.n>y.n) return 0;
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>stu[i].ch>>stu[i].ma>>stu[i].en;
        stu[i].n=i+1;
        stu[i].s=stu[i].ch+stu[i].ma+stu[i].en;
    }
    sort(stu,stu+n,cmp);
    for(int i=0;i<5;i++){
        cout<<stu[i].n<<' '<<stu[i].s<<endl;
    }
}