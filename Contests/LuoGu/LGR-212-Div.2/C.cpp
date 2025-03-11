#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 2933256077;
long long modPow(long long x, long long n) {
    long long result = 1;
    while (n) {
        if (n % 2) result = result * x % MOD;
        x = x * x % MOD;
        n /= 2;
    }
    return result;
}
long long comb(long long n, long long k) {
    if (k > n) return 0;
    vector<long long> fact(n + 1, 1), inv_fact(n + 1, 1);
    for (long long i = 2; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[n] = modPow(fact[n], MOD - 2);
    for (long long i = n - 1; i >= 1; --i) inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}
int main() {
    int n, m;
    cin >> n >> m;
    string S;
    cin >> S;
    vector<int> prefixMatch(n + m + 1, 0);
    for (int i = 0; i <= n + m; ++i) {
        int j = 0;
        while (j <= i && S[j] == S[i]) {
            ++j;
        }
        prefixMatch[i] = j;
    }
    long long result = 0;
    for (int i = 0; i < n + m; ++i) {
        long long total = comb(n + m, n);
        result += total % MOD;
    }
    cout<<result/3 % 2933256077;
}