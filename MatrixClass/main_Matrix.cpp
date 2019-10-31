#include <iostream>
#include "matrix.cpp"

using namespace std;

int main()
{
  try
  {
  
  cout << "sizeof(Matrix) = " << sizeof(Matrix) << endl;
  
  Matrix A ("A", 3, 2);
  A.setElementMatrix(0, 0, 1);
  A.printMatrix();
  
  Matrix B ("B", 3, 2);
  B.setElementMatrix(0, 0, 2);
  B.printMatrix();
  
  Matrix C ("C", 2, 3);
  C.setElementMatrix(0, 0, 3);
  C.printMatrix();

  cout << "\nA == B  ?  ->  " << (A == B) << endl;

  cout << "\nGrand test №1:  A.T.T == A ?" << endl;
  cout << ". . . .  ->  " << ((A.T()).T() == A) << endl;

  cout << "\nGrand test №2:  (A+B).T == A.T + B.T ?" << endl;
  cout << ". . . .  ->  " << (((A+B).T()) == (A.T() + B.T())) << endl;
  
  cout << "\nGrand test №3:  C*(A + B) == C*A + C*B ?" << endl;
  cout << ". . . .  ->  " << ((C*(A + B)) == (C*A + C*B)) << endl;

//  cout << "A == B  is ->\t" << (A == B) << endl;
/*  
  (B*2).printMatrix();
  
  (A + B).printMatrix();
  
  (A - B).printMatrix();
  
  Matrix C ("C", 2, 3);
  C.setElementMatrix(0, 0, 1);
  C.printMatrix();

  C.T().printMatrix();
  
  
  A.printMatrix();
  Matrix F ("F", 2, 3);
  F.printMatrix();
  
  (A*F).printMatrix();
*/  
  }
  
  catch (int)
  {
    cout << "Размеры матриц не согласованы. Попробуйте еще раз!" << endl;
  }
  
  return 0;
}