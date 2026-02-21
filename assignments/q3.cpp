/* 
3. The "Dynamic Network Vulnerability" (Tarjan's Algorithm)

Problem:
Given an undirected graph, find all Critical Links (Bridges).
A bridge is an edge whose removal disconnects the graph.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<pair<int,int>> bridges;

    void dfs(int v, int p) {
        tin[v] = low[v] = timer++;

        for(int to : adj[v]) {
            if(to == p) continue;

            if(tin[to] != -1) {
                // Back edge
                low[v] = min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);

                // Bridge condition
                if(low[to] > tin[v])
                    bridges.push_back({v, to});
            }
        }
    }

public:
    Graph(int n): n(n) {
        adj.resize(n);
        tin.assign(n, -1);
        low.assign(n, -1);
        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int,int>> findBridges() {
        for(int i = 0; i < n; i++)
            if(tin[i] == -1)
                dfs(i, -1);

        return bridges;
    }
};

int main() {
    int n, m;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    Graph g(n);

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<pair<int,int>> bridges = g.findBridges();

    cout << "\nCritical Links (Bridges):\n";

    if(bridges.empty()) {
        cout << "No bridges found.\n";
    } else {
        for(auto &p : bridges)
            cout << p.first << " - " << p.second << endl;
    }

    return 0;
}