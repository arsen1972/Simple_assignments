#pragma once

class Matrix
{

public:
    
  Matrix ();
  Matrix (const string, const int, const int);
  Matrix (Matrix &);

  ~Matrix();
  
  Matrix operator+(const Matrix &);      // Сложение
  Matrix operator-(const Matrix &);      // Вычитание
  Matrix operator*(const Matrix &);      // Умножение
  Matrix & operator*(const int);         // Умножение на число
  Matrix T();                            // Транспониование
 
  bool operator==(const Matrix &) const;  // сравнение матриц на полное равенство
  
};