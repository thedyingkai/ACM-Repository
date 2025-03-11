#include "iostream"
int main(){
    long n;
    scanf("%ld",&n);
    for (int i = 2; i <= n; i++) if (n % i == 0) {
            printf("%ld",n/i);
            return 0;
    }
}