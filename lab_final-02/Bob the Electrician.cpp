
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int m, n, t;
};

vector<Edge> edges;N
vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int m, int n) {
    m = find(m);
    n = find(n);
    if (m != n) {
        parent[m] = n;
        return true;
    }
    return false;
}

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.t < e2.t;
}

int main() {
    int N, T;
    cin >> N >> T;

    for (int i = 0; i < T; i++) {
        int m, n, t;
        cin >> m >> n >> t;
        edges.push_back({m, n, t});
    }

    sort(edges.begin(), edges.end(), compareEdges);

    parent.resize(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    int minCost = 0;
    int edgeCount = 0;

    for (int i = 0; i < T; i++) {
        if (unite(edges[i].m, edges[i].n)) {
            minCost += edges[i].t;
            edgeCount++;
        }
        if (edgeCount == N - 1) {
            break;
        }
    }

    cout << minCost << endl;

    return 0;
}
