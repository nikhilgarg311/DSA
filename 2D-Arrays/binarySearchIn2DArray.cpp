#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(vector< vector<int> > arr, int target){
int rows=arr.size();
int cols=arr[0].size();

int start=0;
int end= rows*cols-1;
while(start<=end){
    int mid= start+(end-start)/2;
    if(arr[mid/cols][mid%cols]==target){
        return 1;
    }
    if(arr[mid/cols][mid%cols]>target){
        end=mid-1;
    }
    if(arr[mid/cols][mid%cols]<target){
        start=mid+1;
    }
}
return 0;
}

int main(){
    int rows=3, cols=4;
    int target=2;
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
    cout << "Does element exist in the matrix?: "<<binarySearch(matrix,target);  // Pass a copy to the function
    return 0;
}