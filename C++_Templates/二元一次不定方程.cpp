#include<iostream>
using namespace std;
int x,y;
int ex_gcd(int a,int b){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int d=ex_gcd(b,a%b);
    int tmp=x;
    x=y;
    y=tmp-a/b*y;
    return d;
}
int main(){
    int a,b,c,d;
    cin>>a>>b>>c;
    d=ex_gcd(a,b);
    if(c%d!=0) cout<<"No solution!"<<endl;
    else{
        cout<<"特解： ";
        cout<<"x="<<c/d*x<<", y="<<c/d*y<<endl;
        cout<<"其他一个解： ";
        cout<<"x="<<c/d*x+(b/d*c)/(d*c/d)<<", y="<<c/d*y-(a/d*c)/(d*c/d)<<endl;
    }
    return 0;
}

