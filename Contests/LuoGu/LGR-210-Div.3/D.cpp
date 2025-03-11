#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

// 矩阵乘法
vector<vector<ll>> matrix_mult(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// 矩阵的快速幂
vector<vector<ll>> matrix_pow(vector<vector<ll>>& matrix, ll power) {
    int n = matrix.size();
    vector<vector<ll>> result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) result[i][i] = 1; // 单位矩阵

    while (power > 0) {
        if (power & 1) {
            result = matrix_mult(result, matrix);
        }
        matrix = matrix_mult(matrix, matrix);
        power >>= 1;
    }
    return result;
}

// 计算能量释放
vector<ll> calculate_energy(int n, ll k, const vector<int>& v, const vector<pair<int, vector<int>>>& atoms) {
    // 初始化邻接表、能量和中子计数
    vector<vector<int>> adj_list(n);
    vector<ll> energy(n, 0), neutron(n, 0);

    // 构建图
    for (int i = 0; i < n; ++i) {
        const auto& [ai, targets] = atoms[i];
        for (int target : targets) {
            adj_list[i].push_back(target - 1); // 转换为 0 索引
        }
    }

    // 初始化第一秒的中子轰击
    for (int vi : v) {
        if (vi >= 1 && vi <= n) neutron[vi-1] += 1;
    }

    // 构建转移矩阵 M 和能量增量矩阵 E
    vector<vector<ll>> M(n, vector<ll>(n, 0)), E(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        M[i][i] = 1; // 自身保持不变
        E[i][i] = 1; // 每次轰击自身增加的能量
        for (int target : adj_list[i]) {
            M[target][i] = 1; // 中子传递
            E[target][i] = 1; // 目标原子获得的能量增量
        }
    }

    // 计算 M^k 和 E^k
    vector<vector<ll>> Mk = matrix_pow(M, k);
    vector<vector<ll>> Ek = matrix_pow(E, k);

    // 更新能量
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            energy[i] = (energy[i] + neutron[j] * Ek[i][j]) % MOD;
        }
    }

    return energy;
}

int main() {
    int n, m;
    ll k;
    cin >> n >> k >> m;
    vector<int> v(m);
    for (int& vi : v) cin >> vi;

    vector<pair<int, vector<int>>> atoms(n);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        vector<int> targets(ai);
        for (int& target : targets) cin >> target;
        atoms[i] = {ai, targets};
    }

    vector<ll> result = calculate_energy(n, k, v, atoms);

    // 输出结果
    for (ll e : result) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}