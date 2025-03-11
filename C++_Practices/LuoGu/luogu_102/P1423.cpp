#include"iostream"
#include "cmath"
using namespace std;
double x;
int main(){
    cin>>x;
    cout<<ceil(log(1-x/100)/log(0.98));
}