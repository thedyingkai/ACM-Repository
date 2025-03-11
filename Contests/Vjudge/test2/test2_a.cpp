#include <iostream>
#include <cmath>
using namespace std;
int n,k;
double x[100086];
bool f(double mid){
    int sum=0;
    for(int i=0;i<n;i++) sum+=(int)(x[i]/mid);
    return sum>=k;
}
int main(){
    cin >> n >> k;
    double sum=0,max=100000,min=0;
    for(int i=0;i<n;i++){
        cin >> x[i];
        sum+=x[i];
    }
    while (max-min>0.0001){
        double mid=(min+max)/2;
        if(f(mid)) min=mid;
        else max=mid;
    }
    printf("%.2lf\n", floor(max*100)/100);
    return 0;
}