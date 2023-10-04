
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph, int start) {
    int n = graph.size();

    vector<int> colors(n, -1);

    colors[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (colors[neighbor] == -1) {
                colors[neighbor] = 1 - colors[node];
            } else if (colors[neighbor] == colors[node]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int num_vertices, num_edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> num_vertices >> num_edges;

    vector<vector<int>> graph(num_vertices);

    cout << "Enter edges (u, v) sequentially:" << endl;
    for (int i = 0; i < num_edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start_node;
    cout << "Enter a starting node for the bipartite check: ";
    cin >> start_node;

    if (isBipartite(graph, start_node)) {
        cout << "Yes, the graph is bipartite." << endl;
    } else {
        cout << "No, the graph is not bipartite." << endl;
    }

    return 0;
}
