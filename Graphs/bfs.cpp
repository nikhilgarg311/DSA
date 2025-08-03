//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<int> &ans, bool *visited,int node,vector<vector<int>> &adj){
        queue<int> q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(int j=0;j<adj[front].size();j++){
                if(!visited[adj[front][j]]){
                    q.push(adj[front][j]);
                    visited[adj[front][j]]=true;
                }
            }
        }
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        int n= adj.size();
        bool visited[n]={false};
        //if you want to print the disconnected graph then add a loop here for all nodes
            if(!visited[0]){
                bfs(ans,visited,0,adj);
            }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends