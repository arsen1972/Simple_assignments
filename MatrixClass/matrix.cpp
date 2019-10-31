#include <iostream>
//#include "matrix.h"

using namespace std;

class Matrix
{
private:
 string name;
 int rows;
 int cols;
 int** arr;
 
public:
    
// ****************************************************** constructors:
  Matrix (){}

// ****************************************************** constructors: parametrs
  Matrix (const string name, const int n, const int m)
  { 
    this->name = name;
    this->rows = n;
    this->cols = m;
    
    this->arr = new int*[rows];
    
    for (int i=0; i<rows; i++) arr[i] = new int[cols];
    
    for (int i=0; i<rows; i++)
    { for(int j=0; j<cols; j++) arr[i][j] = 1+i+j;}

  }

// ****************************************************** constructors: = copy
  Matrix (Matrix & matrix)
  { 
    this->name = matrix.name + "_copy";
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    
    this->arr = new int*[rows];
    
    for (int i=0; i<rows; i++) 
    {
      this->arr[i] = new int[cols];
    }
    
    for (int i=0; i<this->rows; i++)
    { for(int j=0; j<this->cols; j++) 
      { this->arr[i][j] = 0;             // все в "0"
      }
    }
    
    for (int i=0; i<this->rows; i++)
    { 
      for(int j=0; j<this->cols; j++) 
      {
        this->arr[i][j] = matrix.arr[i][j];  // копируем
      }
    }
    //cout << "\ncopy Matrix()" << endl;
  }

// *******************************************************  destructors:
  ~Matrix()
  { for (int i=0; i<rows; i++) delete [] arr[i];
    delete [] arr; 
    //cout << "delete ~Matrix()" << endl;
  }
  
// *******************************************************  operator+:  
Matrix operator+(const Matrix & matrix)
{ 
  if (isOfEqualityOfMatrixDimention (*this, matrix))
  { 
    //cout << "Matrix dimentions correct! GOOD!!!" << endl;
    Matrix Temp((this->name + " + " + matrix.name), rows, cols);
  
    for (int i=0; i<this->rows; i++)
    { 
      for(int j=0; j<this->cols; j++) 
      { 
        Temp.arr[i][j] = this->arr[i][j] + matrix.arr[i][j];
    } } 
    
    return Temp;
  }
  
  else
  {
    //cout << "Matrix dimentions not correct! BAD!!!" << endl;
    throw -1;
  }

}

// *******************************************************  operator-:  
Matrix operator-(const Matrix & matrix)
{ 
  if (isOfEqualityOfMatrixDimention (*this, matrix))
  { 
    //cout << "Matrix dimentions correct! GOOD!!!" << endl;
    
  Matrix Temp((this->name + " - " + matrix.name), rows, cols);
  
  for (int i=0; i<this->rows; i++)
  { 
    for(int j=0; j<this->cols; j++) 
    { 
      Temp.arr[i][j] = this->arr[i][j] - matrix.arr[i][j];
  } }
  return Temp;
  }
  
  else
  {
    //cout << "Matrix dimentions not correct! BAD!!!" << endl;
    throw -1;
  }
  
}

// *******************************************************  operator*:

Matrix operator*(const Matrix & matrix)
{
  Matrix Temp((this->name + " * " + matrix.name), this->rows, matrix.cols);
 
  Temp.equalValuePadding(0);
  //Temp.printMatrix();
  
  if (this->cols == matrix.rows)
  { for (int i=0; i<Temp.rows; i++)
    { for (int j=0; j<matrix.cols; j++)
      { for (int k=0; k<Temp.cols; k++)
        { Temp.arr[i][j] += this->arr[i][k] * matrix.arr[k][j];
    } } }
    
    return Temp;
  }
  
  else
  { throw -1;
  }
}

// *******************************************************  operator*(int):  
Matrix & operator*(int a)
  { 
    for (int i=0; i<this->rows; i++)
    {
      for(int j=0; j<this->cols; j++) 
      {
        this->arr[i][j] = this->arr[i][j] * a;
    } }
    return *this;
  }

// *******************************************************  T: 
  Matrix T()
{ 
  Matrix Temp;
  Temp.name = this->name + "T";
  Temp.rows = this->cols;
  Temp.cols = this->rows;
  
  Temp.arr = new int*[rows];
    
    for (int i=0; i<Temp.rows; i++) 
    {
      Temp.arr[i] = new int[cols];
    }
    
    for (int i=0; i<Temp.rows; i++)
    { for(int j=0; j<Temp.cols; j++) 
      { Temp.arr[i][j] = 0;
      }
    }

  for (int i=0; i<Temp.rows; i++)
  { 
    for(int j=0; j<Temp.cols; j++) 
    {
      Temp.arr[i][j] = this->arr[j][i];
    }
  }
  return Temp;
}

// ******************************************************************************  operator==

bool operator==(const Matrix & matrix) const
{ 
  bool isEqual = true;
  
  if (this->rows == matrix.rows && this->cols == matrix.cols)
  { 
    for (int i=0; i<matrix.rows; i++)
    {
      for (int j=0; j<matrix.cols; j++)
      { 
        if (this->arr[i][j] != matrix.arr[i][j])
        { isEqual = false;
          break;
  } } } }
  
  else
  { isEqual = false;
  }
  
  return isEqual;
}

// *******************************************************************************  printMatrix()
void printMatrix()
{ 
  cout << "\nName of array: " << name << "\tRows = " << rows << "\tCols = " << cols << endl;
  
  for (int i=0; i<rows; i++)
  { 
    for (int j=0; j<cols; j++) 
    {
      cout << arr[i][j] << "\t";
    }
    cout << endl;
} }

// *******************************************************  setMatrix:
void setElementMatrix(int i, int j, int a)
  { arr[i][j] = a;
  }
  
private:
// ******************************************************* isOfEqualityOfMatrixDimention
bool isOfEqualityOfMatrixDimention (const Matrix & M1, const Matrix & M2)
{
  bool isEqualityOfMatrixDimention = false;
  if ((M1.rows == M2.rows) && (M1.cols == M2.cols))
  { isEqualityOfMatrixDimention = true;
  }
  
  else
  { throw -1;
  }
  
  return isEqualityOfMatrixDimention;
}

// ******************************************************* equalValuePadding
Matrix & equalValuePadding(int num)
{ for (int i=0; i<this->rows; i++)
  { for(int j=0; j<this->cols; j++) 
    { this->arr[j][i] = num;
  } }
  return *this;
}

};













