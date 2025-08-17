class Solution {
  public:
  
    bool bfs(int V,int node,vector<vector<int>>& adj,vector<bool> &visited, unordered_map<int,int> &parent){
        queue<int> q;
        q.push(node);
        parent[node]= -1;
        visited[node]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(int j=0;j<adj[front].size();j++){
                if(visited[adj[front][j]] && adj[front][j]!=parent[front]){
                    return true;
                }
                else if(!visited[adj[front][j]]){
                    parent[adj[front][j]]=front;
                    q.push(adj[front][j]);
                    visited[adj[front][j]]=true;
                }
                
            }
        }
        return false;
    }
    
    bool dfs(int V,int node,vector<vector<int>>& adj,vector<bool> &visited, int parent){
    visited[node]=true;
    for (int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){;
            bool ans=dfs(V,adj[node][i],adj,visited,node);
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
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        //unordered_map<int,int> parent;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V,false);
        // for(int i=0;i<V;i++){
        //     if(!visited[i]){
        //     unordered_map<int,int> parent;
        //       bool ans=bfs(V,i,adj,visited,parent);
        //       if(ans){
        //           return ans;
        //       }
        //     }
        // }
        //return false;
        for(int i=0;i<V;i++){
            if(!visited[i]){
              bool ans=dfs(V,i,adj,visited,-1);
              if(ans){
                  return ans;
              }  
            }
        }
        return false;
        
    }
};