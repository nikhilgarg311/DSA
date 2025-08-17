class Solution {
  public:
  
    void kahnsAlgo(vector<vector<int>>& adj, vector<int> &indegree, vector<int> &ans){
        
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front=q.front();
            ans.push_back(front);
            q.pop();
            for(int i=0;i<adj[front].size();i++){
                indegree[adj[front][i]]--;
                if(indegree[adj[front][i]]==0){
                    q.push(adj[front][i]);
                }
            }
        }
        return;
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        kahnsAlgo(adj,indegree,ans);
        return ans;
        
        
    }
};