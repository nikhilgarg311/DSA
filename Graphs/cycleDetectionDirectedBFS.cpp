//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/**
 * Kahn's Algo is topologicalSort using BFS
 */

 
// } Driver Code Ends

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    
    bool topologicalSortBFS(vector<vector<int>>& adj, int *indegree){
    queue<int> q;
    for(int i=0;i<adj.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        count++;
        for(int i=0;i<adj[front].size();i++){
            indegree[adj[front][i]]--;
            if(indegree[adj[front][i]]==0){
                q.push(adj[front][i]);
            }
        }
    }
    if(count==adj.size()){
        return true;
    }
    
    }

    bool topologicalSort(vector<vector<int>>& adj) {
        int n=adj.size();
        int indegree[n]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        return topologicalSortBFS(adj,ans,indegree);
    }
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends