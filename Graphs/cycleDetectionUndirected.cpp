//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectCycleBFS(vector<vector<int>>& adj, bool *visited, int node,unordered_map<int,int> &parent){
        parent[node]=-1;
        visited[node]=true;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(int i=0;i<adj[front].size();i++){
                if(visited[adj[front][i]] && adj[front][i]!=parent[front]){
                    return true;
                }
                else if(!visited[adj[front][i]]){
                    parent[adj[front][i]]=front;
                    q.push(adj[front][i]);
                    visited[adj[front][i]]=true;
                }
            }
        }
        return false;
    }
    bool detectCycleDFS(vector<vector<int>>& adj, bool *visited, int node,int parent){
        visited[node]=true;

        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                bool ans= detectCycleDFS(adj,visited,adj[node][i],node);
                if(ans){
                    return true;
                }
            }
            else if(adj[node][i]!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        bool ans=false;
        int n=adj.size();
        bool visited[n]={false};
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans=detectCycleDFS(adj,visited,i,-1);
                if(ans){
                    return ans;
                }
            }
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
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends