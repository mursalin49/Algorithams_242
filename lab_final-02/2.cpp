#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to;
    int time;
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<Edge>> graph(V);
    vector<int> distance(V, INF);

    for (int i = 0; i < E; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }

    int pizzaLocation;
    cin >> pizzaLocation;

    distance[pizzaLocation] = 0;

    vector<bool> visited(V, false);
    for (int i = 0; i < V - 1; i++) {
        int minDist = INF, u = -1;

        for (int j = 0; j < V; j++) {
            if (!visited[j] && distance[j] < minDist) {
                minDist = distance[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int t = edge.time;

            if (!visited[v] && distance[u] + t < distance[v]) {
                distance[v] = distance[u] + t;
            }
        }
    }

    int totalDeliveryTime = 0;
    for (int i = 0; i < V; i++) {
        if (i != pizzaLocation) {
            totalDeliveryTime += distance[i];
        }
    }

    cout << totalDeliveryTime << endl;

    return 0;
}
