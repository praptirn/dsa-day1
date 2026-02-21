/*3. The "Dynamic Network Vulnerability" (Tarjan's/Graphs)
○ Problem: Given a communication network represented as an undirected graph,
identify all "Critical Links" (Bridges). A link is critical if its removal disconnects the
network.

Solution:
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Graph {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<pair<int,int>> bridges;

    void dfs(int v, int p){
        tin[v] = low[v] = timer++;

        for(int to : adj[v]){
            if(to == p) continue;

            if(tin[to] != -1){
                low[v] = min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);

                if(low[to] > tin[v])
                    bridges.push_back({v,to});
            }
        }
    }

public:
    Graph(int n): n(n){
        adj.resize(n);
        tin.assign(n,-1);
        low.assign(n,-1);
        timer=0;
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int,int>> findBridges(){
        for(int i=0;i<n;i++)
            if(tin[i]==-1) dfs(i,-1);
        return bridges;
    }
};
