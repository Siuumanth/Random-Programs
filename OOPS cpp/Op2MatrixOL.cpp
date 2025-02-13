#include <iostream>
using namespace std;

class matrix {
private:
    long m[5][5]; // Matrix storage
    int row, col; // Number of rows and columns

public:
    void getdata();                     // Function to get matrix data
    int operator==(matrix);              // Overloaded equality operator to compare matrix order
    matrix operator+(matrix);            // Overloaded addition operator for matrix addition
    matrix operator-(matrix);            // Overloaded subtraction operator for matrix subtraction
    friend ostream& operator<<(ostream&, matrix&); // Friend function to print matrix
};

/* Function to check whether the order of matrices are the same */
int matrix::operator==(matrix cm) {
    if (row == cm.row && col == cm.col) {
        return 1; // Matrices are of the same order
    }
    return 0; // Matrices are not of the same order
}

/* Function to read data for a matrix */
void matrix::getdata() {
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;
    
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> m[i][j];
        }
    }
}


/* Function to add two matrices */
matrix matrix::operator+(matrix am) {
    matrix temp;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp.m[i][j] = m[i][j] + am.m[i][j]; // Add corresponding elements
        }
    }

    temp.row = row;
    temp.col = col;
    return temp;
}

/* Function to subtract two matrices */
matrix matrix::operator-(matrix sm) {
    matrix temp;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp.m[i][j] = m[i][j] - sm.m[i][j]; // Subtract corresponding elements
        }
    }

    temp.row = row;
    temp.col = col;
    return temp;
}

/* Function to display the contents of the matrix */
ostream& operator<<(ostream& fout, matrix& d) {
    for (int i = 0; i < d.row; i++) { // Fix: iterate over rows instead of d.col
        for (int j = 0; j < d.col; j++) { // Fix: iterate over columns instead of d.col
            fout << d.m[i][j] << " "; // Print matrix element
        }
        fout << endl;
    }
    return fout;
}

/* Main function */
int main() {
    matrix m1, m2, m3, m4;

    // Input matrices
    m1.getdata();
    m2.getdata();

    // Check if matrix orders are the same
    if (m1 == m2) {
        // Perform matrix addition
        m3 = m1 + m2;
        cout << "Addition of matrices:\n" << m3;

        // Perform matrix subtraction
        m4 = m1 - m2;
        cout << "Subtraction of matrices:\n" << m4;
    } else {
        cout << "Error: Orders of the input matrices are not identical.\n";
    }

    return 0;
}
