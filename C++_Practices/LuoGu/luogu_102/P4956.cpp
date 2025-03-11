#include "iostream"
using namespace std;
int main() {
    int nn;
    cin>>nn;
    int n = nn/364;
    if (n <= 103) printf("%d\n%d\n", n - 3, 1);
    else {
        if (n % 3 == 0) printf("%d\n%d\n", 99, (n - 99) / 3);
        if (n % 3 == 1) printf("%d\n%d\n", 100, (n - 100) / 3);
        if (n % 3 == 2) printf("%d\n%d\n", 98, (n - 98) / 3);
    }
}