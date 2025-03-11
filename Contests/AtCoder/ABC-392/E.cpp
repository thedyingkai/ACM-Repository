//
// Created by ASUS on 2025/2/8.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class UnionFind {
    vector<int> parent, rank;
public:
    explicit UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind uf(N + 1);
    vector<pair<int, int>> connections(M);
    vector<pair<int, int>> redundantEdges;

    // Process existing cables
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        connections[i] = {a, b};
        if (uf.find(a) == uf.find(b))
            redundantEdges.push_back({a, b});
        else
            uf.unite(a, b);
    }

    // Count connected components
    unordered_set<int> components;
    for (int i = 1; i <= N; ++i)
        components.insert(uf.find(i));

    int numComponents = components.size();

    if (numComponents == 1) {
        cout << "0\n";
        return 0;
    }

    // Number of operations needed is numComponents - 1
    int opsNeeded = numComponents - 1;
    if (redundantEdges.size() < opsNeeded) {
        cout << "-1\n"; // Not enough redundant edges to connect all servers.
        return 0;
    }

    cout << opsNeeded << "\n";

    // Use redundant edges to connect components
    unordered_set<int> usedRoots;
    for (const auto& edge : redundantEdges) {
        if (opsNeeded == 0) break;
        int rootA = uf.find(edge.first), rootB = uf.find(edge.second);

        if (usedRoots.count(rootA) == 0 && usedRoots.count(rootB) == 0) {
            // Choose one of the roots that hasn't been used yet and connect it to another component
            usedRoots.insert(rootA);
            usedRoots.insert(rootB);
            cout << edge.first << " " << edge.second << " " << (rootA == uf.find(1) ? rootB : rootA) << "\n";
            opsNeeded--;
        }
    }

    return 0;
}