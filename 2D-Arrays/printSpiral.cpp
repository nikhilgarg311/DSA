#include<iostream>
#include<vector>
using namespace std;

void spiral(vector< vector<int> > arr){
int rows=arr.size();
int cols=arr[0].size();
int count=0;
int total=rows*cols;

int startingRow=0;
int startingCol=0;
int endingRow=rows-1;
int endingCol=cols-1;

while(count<total){
    //print strating row
    for(int index=startingCol;index<=endingCol && count<total;index++){
        cout<<arr[startingRow][index]<<" ";
        count++;
    }
    startingRow++;
    //print ending column
    for(int index=startingRow;index<=endingRow && count<total;index++){
        cout<<arr[index][endingCol]<<" ";
        count++;
    }
    endingCol--;
    //print ending row
    for(int index=endingCol;index>=startingCol && count<total;index--){
        cout<<arr[endingRow][index]<<" ";
        count++;
    }
    endingRow--;
    //print starting column
    for(int index=endingRow;index>=startingRow && count<total;index--){
        cout<<arr[index][startingCol]<<" ";
        count++;
    }
    startingCol++;
}
}
int main(){
    int rows, cols;

    // Take the number of rows and columns as input
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Create a 2D vector of size (rows x cols)
    vector< vector<int> > matrix(rows, vector<int>(cols));

    // Take input for the 2D vector (matrix)
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];  // Input each element
        }
    }

    // Print the 2D vector elements in spiral pattern
    cout << "Spiral traversal of the matrix is:\n";
    spiral(matrix);  // Pass a copy to the function

    return 0;
}