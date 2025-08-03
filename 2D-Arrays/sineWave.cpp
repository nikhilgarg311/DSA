#include <iostream>
#include <vector>
using namespace std;

// Function to print the 2D vector in sinewave pattern, passing by value (copy)
void sinewaveTraversal(vector< vector<int> > matrix, int rows, int cols) {
    for (int j = 0; j < cols; ++j) {
        if (j % 2 == 0) {
            // Traverse the column from top to bottom for even-numbered columns
            for (int i = 0; i < rows; ++i) {
                cout << matrix[i][j] << " ";
            }
        } else {
            // Traverse the column from bottom to top for odd-numbered columns
            for (int i = rows - 1; i >= 0; --i) {
                cout << matrix[i][j] << " ";
            }
        }
    }
    cout << endl;
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
    sinewaveTraversal(matrix, rows, cols);  // Pass a copy to the function

    return 0;
}
