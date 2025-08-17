class Solution {
  public:
  
    bool dfs( vector<vector<int>> &adj, int node,vector<bool> &visited,vector<bool> &dfsVisited ){
        visited[node]=true;
        dfsVisited[node]=true;
        
        for(int i=0;i<adj[node].size();i++){
            if(visited[adj[node][i]] && dfsVisited[adj[node][i]] ){
                return true;
            }
            else if(!visited[adj[node][i]]){
                bool ans=dfs(adj,adj[node][i],visited,dfsVisited);
                if(ans){
                    return true;
                }
            }
            
        }
        dfsVisited[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        // Code here
        vector<vector<int>> adj(V);
        //unordered_map<int,int> parent;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<bool> visited(V,false);
        vector<bool> dfsVisited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=dfs(adj,i,visited,dfsVisited);
                if(ans){
                    return ans;
                }
            }
        }
        return false;
    }
};