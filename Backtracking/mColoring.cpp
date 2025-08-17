class Solution {
  public:
  
    bool isSafe(int vertice,vector<int> &colored,vector<vector<int>> &adj,int color ){
        for(int i=0;i<adj[vertice].size();i++){
            if(colored[adj[vertice][i]]==color){
                return false;
            }
        }
        return true;
    }
    bool solve(int v,vector<vector<int>> &adj, int m,vector<int> &colored,int V){
       //base case
       if(v==V){
           return true;//all colored
       }
       
       for(int i=1;i<=m;i++){
           if(isSafe(v,colored,adj,i)){
               colored[v]=i;
               if(solve(v+1,adj,m,colored,V))return true;
               colored[v]=0;
           }
           
       }
       
       return false;
       
    }
  
    bool graphColoring(int V, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> colored(V,0);//0 means uncolored;
    return solve(0,adj,m,colored,V);
    }
};