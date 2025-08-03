//rotate a n x n matrix

#include<iostream>
#include<vector>
using namespace std;

void rotate(vector< vector<int> > arr){
    int n=arr.size();
    //swap the elements
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    
    //reverse the rows
    for(int k=0;k<n;k++){
        int start=0,end=n-1;
        while(start<end){
            swap(arr[k][start],arr[k][end]);
            start++;end--;
        }
    }
    
    //print
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<arr[i][j]<<" ";  // output each element
        }
        cout<<endl;
    }



}
int main(){
   int rows=4,cols=4;

    // Create a 2D vector of size (rows x cols)
    vector< vector<int> > matrix(rows, vector<int>(cols));

    // Take input for the 2D vector (matrix)
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];  // Input each element
        }
    }

    cout << "given matrix is:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout<<matrix[i][j]<<" ";  // output each element
        }
        cout<<endl;
    }

    cout << "rotated matrix is:\n";
    rotate(matrix);  // Pass a copy to the function
}