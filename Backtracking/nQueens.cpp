// User function Template for C++

class Solution {
  public:
    bool isSafe(int row,int col,vector< vector<int> > &board,int n){
        int x=row;
        int y=col;
        
        //check same row
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        
        y=col;
        
        //check for upper diagonal
        while(x>=0 && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        //check for bottom diagonal
        x=row;
        y=col;
        
        while(x<n && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        
        return true;
        
    }
    
    void solve(int col,vector< vector<int> > &board,vector< vector<int> > &ans,int n){
        if(col==n){
            //convert board to ans
            vector<int> temp;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[j][i]==1){
                        temp.push_back(j+1);
                    }
                }
            }
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
           if(isSafe(i,col,board,n)){
            
            board[i][col]=1;
            solve(col+1,board,ans,n);
            
            board[i][col]=0;
           } 
        }
        
        return;
    }
  
    vector<vector<int>> nQueen(int n) {
        // code here
        vector< vector<int> > ans;
        vector< vector<int> > board(n,vector<int>(n,0));
        solve(0,board,ans,n);
        return ans;
    }
};