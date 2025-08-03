/* Online C++ Compiler and Editor */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sinewaveTraversal(int rows, int cols, vector< vector<int> > &matrix){
    for(int i=0;i<cols;i++){
        
        if(i%2!=0){
            for(int j=0;j<rows;j++){
                cout<<matrix[j][i]<<" ";
            }
        }
        else{
            for(int j=rows-1;j>=0;j--){
            cout<<matrix[j][i]<<" ";
            }
        }
        cout<<endl;
    }
}

void spiralTraversal(int rows,int cols, vector< vector<int> > &matrix){
    int count=0;
    int total=rows*cols;
    
    int startingRow=0;
    int startingCol=0;
    int endingRow=rows-1;
    int endingCol=cols-1;
    
    while(count<total){
        //print row
        for(int i=startingCol;i<=endingCol && count<total;i++){
            cout<<matrix[startingRow][i]<<" ";
            count++;
        }
        startingRow++;
        //print col
        for(int i=startingRow; i<=endingRow && count<total; i++){
            cout<<matrix[i][endingCol]<<" ";
            count++;
        }
        endingCol--;
        //print row
        for(int i=endingCol;i>=startingCol && count<total; i--){
            cout<<matrix[endingRow][i]<<" ";
            count++;
        }
        endingRow--;
        //print col 
        for(int i=endingRow;i>=startingRow && count<total;i--){
            cout<<matrix[i][startingCol]<<" ";
            count++;
        }
        startingCol++;
    }
}

void rotateMatrix(int rows, int cols, vector< vector<int> > &matrix){
    //transpose of matrix
    for(int i=0;i<rows;i++){
        for(int j=i+1;j<cols;j++){
            swap(matrix[i][j],matrix[j][i]);
    }
    }
    //reverse rows
    for(int i=0;i<rows;i++){
        int start=0,end=rows-1;
        while(start<end){
            swap(matrix[i][end],matrix[i][start]);
            start++;end--;
        }
    }
    
     //print
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout<<matrix[i][j]<<" ";  // output each element
        }
        cout<<endl;
    }
}

bool binarySearch(int rows, int cols, vector< vector<int> > &arr,int n){
    int start=0,end=rows*cols-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid/cols][mid%cols]>n){
            end=mid-1;
        }
        else if(arr[mid/cols][mid%cols]<n){
            start=mid+1;   
        }
        else{
            return true;
        }
    }
    return false;
}

int main() {
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
    // Print the 2D vector elements in sinewave pattern
    cout << "Sinewave traversal of the matrix is:\n";
    sinewaveTraversal(rows, cols, matrix);
    cout << "Spiral traversal of the matrix is:\n";
    spiralTraversal(rows, cols, matrix); 
    // cout<< "\nRotating the matrix 90deg clockiwise:\n";
    // rotateMatrix(rows,cols,matrix);
    int num;
    cout<< "\nType number to be searched: ";cin>>num;
    cout<< binarySearch(rows,cols,matrix,num); //note matrix should be sorted
    return 0;
}