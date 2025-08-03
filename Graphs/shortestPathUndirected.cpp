//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
  
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
       int n = adj.size();
        vector<int> dist(n, -1); // Distance array to store shortest path length
        queue<int> q;
        
        dist[src] = 0;  // Distance to source is 0
        q.push(src);     // Start BFS from the source
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Explore the neighbors of the current node
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {  // If the node hasn't been visited yet
                    dist[neighbor] = dist[node] + 1;  // Update distance
                    q.push(neighbor);  // Enqueue the neighbor
                }
            }
        }
        
        return dist;  // Return the shortest path lengths to all nodes
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends