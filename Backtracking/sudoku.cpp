class Solution {
  public:
    // Function to find a solved Sudoku.

    bool isValid(vector<vector<int>> &mat, int k, int row, int col) {
    int boxRow = 3 * (row / 3);
    int boxCol = 3 * (col / 3);

    for (int i = 0; i < 9; i++) {
        // Check row & column in one loop
        if (mat[row][i] == k || mat[i][col] == k) return false;

        // Check 3×3 subgrid
        int r = boxRow + i / 3;
        int c = boxCol + i % 3;
        if (mat[r][c] == k) return false;
    }
    return true;
}
    
    bool solve(vector<vector<int>> &mat){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]==0){
                    for(int k=1;k<=9;k++){
                        if(isValid(mat,k,i,j)){
                            mat[i][j]=k;
                            if(solve(mat)){
                                return true;
                            }
                            mat[i][j]=0;
                        }
                    }
                    return false;//no valid num
                }
                
            }
        }
        return true;
        
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        bool ans=solve(mat);
        return;
    }
};