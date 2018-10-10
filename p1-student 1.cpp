// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 1
// Program: CS213-2018-A1-T1-P1
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int* data;       // Pointer to 1-D array that will simulate matrix
  int row, col;
  friend ostream&operator<< (ostream & print , matrix& mat );
};
// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);
ostream&operator<< (ostream & print , matrix mat ){

    for(int i = 0 ; i < mat.row ; i++ ){
        for(int j = 0 ; j < mat.col ; j++){
            print<<mat.data[i*mat.col+j]<<' ' ;
        }
        print<<endl;
    }
    return print;
  }
// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2) // Add if same dimensions
{
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]+mat2.data[i];
    }
    return mat4;
}
matrix operator-  (matrix mat1, matrix mat2){ // Sub if same dimensions
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]-mat2.data[i];
    }
    return mat4;
}
matrix operator*  (matrix mat1, matrix mat2) // Multi if col1 == row2
{
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]* mat2.data[i];
    }
    return mat4;
}
matrix operator+  (matrix mat1, int scalar) // Add a scalar
{
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]+scalar;
    }
    return mat4;
}
matrix operator-  (matrix mat1, int scalar)  // Subtract a scalar
{

    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]-scalar;
    }
    return mat4;
}
matrix operator*  (matrix mat1, int scalar)  // Multiple by scalar
{
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]*scalar;
    }
    return mat4;
}

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8,9};
  int data2 [] = {1,2,3,4,5,6,7,8,9};
  int data3 [] = {10,100,10,100,10,100,10,100};

  matrix mat1, mat2, mat3;
  createMatrix (3, 3, data1, mat1);
  createMatrix (3, 3, data2, mat2);
  createMatrix (3, 3, data3, mat3);
  cout << mat1 + mat2 << endl;
  cout << mat1 - mat2 << endl;
  cout << mat1 * mat2 << endl;
  cout << mat1 + 10 << endl;
  cout << mat1 - 1 << endl;
  cout << mat1 * 5 << endl;
/* The next code will not work until you write the functions
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;

  cout << (mat1 + mat3) << endl << endl;
  cout << (mat3 + mat3) << endl << endl;

  ++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  // Add more examples of using matrix
  // .......
*/
  return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int [row * col];
  for (int i = 0; i < row * col; i++)
    mat.data [i] = num [i];
}
