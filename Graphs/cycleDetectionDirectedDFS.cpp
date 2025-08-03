//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclicDFS(vector<vector<int>> &adj, bool *visited, bool *dfsVisited,int node){
        visited[node]=true;
        dfsVisited[node]=true;
        
        for(int i=0;i<adj[node].size();i++){
            if(visited[adj[node][i]] && dfsVisited[adj[node][i]]){
                return true;
            }
            else if(!visited[adj[node][i]])
            {
                bool ans=isCyclicDFS(adj,visited,dfsVisited,adj[node][i]);
                if(ans){
                    return true;
                }
            }
        }
        dfsVisited[node]=false;
        return false;
    }
    
    
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int n= adj.size();
        bool visited[n]={false};
        bool dfsVisited[n]={false};
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool ans=isCyclicDFS(adj,visited,dfsVisited,i);
                if(ans){
                    return true;
                }
            }
        }
        return false;
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
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends