class Solution {
  public:
  
   void dfs(vector<vector<int>>& adj,int node,vector<bool> &visited,stack<int> & s){
        visited[node]=true;        
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfs(adj,adj[node][i],visited,s);
            }
        }
        s.push(node);
        return;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> ans;
        vector<bool> visited(V,false);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,i,visited,s);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
        
        
    }
};