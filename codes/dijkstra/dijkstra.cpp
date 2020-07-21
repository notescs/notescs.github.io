#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e6;
using ii = pair<int, int>;

void printPath(vector<int> &prev, int i) {
    while (i >= 0) {
        cout << i << " ";
        i = prev[i];
    }
}

void dijkstra(int n, vector<vector<ii>> &graph, int source) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<int> dist(n, INF);
    vector<int> prev(n, -1);
    pq.push({0, source});
    dist[source] = 0;
    while (!pq.empty()) {
        auto [dist_u, u] = pq.top(); // works with c++17 onwards
        // for before c++17
        // int dist_u = pq.top().first;
        // int u = pq.top().second;
        pq.pop();
        if (dist_u != dist[u]) continue;
        for (auto neighbor: graph[u]) {
            auto [v, weight] = neighbor; // works with c++17 onwards
            // for before c++17
            // int v = neighbor.first;
            // int weight = neighbot.second;
            // Relaxation step
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << "Distance from " << source << " and " << i << ": " << dist[i] << "\n";
        cout << "Route is: ";
        printPath(prev, i);
        cout << "\n";
    }
}

int main() {
    const int N = 9;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 7},
        {1, 2},
        {1, 7},
        {2, 3},
        {2, 8},
        {2, 5},
        {3, 4},
        {3, 5},
        {4, 5},
        {5, 6},
        {6, 7},
        {6, 8},
        {7, 8},
    };
    vector<int> weights = {4, 8, 8, 11, 7, 2, 4, 9, 14, 10, 2, 1, 6, 7};
    vector<vector<ii>> graph(N);
    for (int i = 0; i < (int)edges.size(); ++i) {
        graph[edges[i][0]].push_back({edges[i][1], weights[i]});
        graph[edges[i][1]].push_back({edges[i][0], weights[i]});
    }
    dijkstra(N, graph, 0);
}
