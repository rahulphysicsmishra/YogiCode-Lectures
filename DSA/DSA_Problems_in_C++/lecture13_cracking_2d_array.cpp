// lecture 13 : cracking 2D array problem

/*
1 : What is a 2D Array (Matrix)?
Alright, before we touch code, let’s visualize what a 2D array really is.

If you’ve already worked with 1D arrays, you know they’re like a simple row of lockers, 
numbered one after another:

[ 10 | 20 | 30 | 40 | 50 ]
  0    1    2    3    4
Each locker (or index) holds a single value.

A 2D array, on the other hand, is like a whole building of lockers, arranged in rows and columns:
[ [10 | 20 | 30],
  [40 | 50 | 60],
  [70 | 80 | 90] ]

  Here, you have multiple rows (like floors) and columns (like lockers on each floor).
To access an element, you need two indices: one for the row and one for the column.
For example, to get the value 50, you’d go to row 1, column 1 (remembering we start counting from 0).
This structure is super useful for representing grids, tables, or any data that has two dimensions.


*/

// Problem : Transpose of a Matrix
// Given a 2D array (matrix) of size rows × cols, return its transpose.

#include <iostream>
#include <vector>
using namespace std;

// Function to transpose a matrix
vector<vector<int>> transposeMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();            // Number of rows in original
    int cols = matrix[0].size();         // Number of columns in original

    // Create a new matrix with dimensions swapped (cols x rows)
    vector<vector<int>> transpose(cols, vector<int>(rows));

    // Loop through each cell of original matrix
    for (int i = 0; i < rows; i++) {             // Outer loop → rows
        for (int j = 0; j < cols; j++) {         // Inner loop → columns
            transpose[j][i] = matrix[i][j];      // Flip indices!
        }
    }

    return transpose;
}

// Function to print a 2D matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Sample matrix (2x3)
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    vector<vector<int>> result = transposeMatrix(matrix);

    cout << "\nTransposed Matrix:\n";
    printMatrix(result);

    return 0;
}

