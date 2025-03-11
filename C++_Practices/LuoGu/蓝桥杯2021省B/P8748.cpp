#include "iostream"
using namespace std;
long long n;
int hh,mm,ss;
int main(){
    cin>>n;
    n/=1000;
    ss=n%60;
    n/=60;
    mm=n%60;
    n/=60;
    hh=n%24;
    printf("%02d:%02d:%02d",hh,mm,ss);
}