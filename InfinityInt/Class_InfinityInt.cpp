#include <string.h>
#include <iostream>
#include <vector>
//#include "InfinityInt.h"

using namespace std;

class InfinityInt
{
private:
  vector<short> digits;
  char sign;

public:
// ********************************************************   constructors:
  InfinityInt()
  { sign = '+';
  }

// ********************************************************   constructors: const char*
InfinityInt(const char* str)
{ 
  if (str[0]=='-') 
    { sign = '-';
      for (short i=1; i<strlen(str); i++)
      { if (!isdigit(str[i])) 
        { throw -1;
        }
        else 
        { digits.push_back(short(str[i]-'0'));
    } } }
    
  else
    { for (short i=0; i<strlen(str); i++)
      { if (!isdigit(str[i])) 
        { throw -1;
        }
        else 
        { sign = '+';
          digits.push_back(short(str[i]-'0'));
}   } } }

// ********************************************************  constructors: const long int
InfinityInt(long int number)
{ 
  short n;
  InfinityInt Temp;
  
  if (number>0)
  { sign = '+';
  }
  else if (number<0)
  { sign = '-';
    number = abs(number);
  }
   
  while (number != 0)
  { n = number%10;
    number /=10;
    Temp.digits.push_back(n);
  }  
  
  for (short i=0; i<Temp.digits.size(); i++)
  { digits.push_back(Temp.digits[(Temp.digits.size())-1-i]);
} }

//**********************************************************  constructors: = copy
InfinityInt(const InfinityInt & inf)
{ 
  this->sign = inf.sign;
  
  for (short i=0; i<inf.digits.size(); i++)
  { digits.push_back(inf.digits[i]);
} }

// *********************************************************  destructor:
~InfinityInt()
{}

// *********************************************************  operator=
InfinityInt & operator=(const InfinityInt & inf)
{ 
  this->sign = inf.sign ;
  digits.clear();
  
  for (size_t i=0; i<inf.digits.size(); i++)
  { digits.push_back(inf.digits[i]);
  }
  
  return *this;
}   
// *********************************************************  operator+
InfinityInt operator+(InfinityInt & inf)
{ 
  InfinityInt TempMax;
  InfinityInt TempMin;
  InfinityInt Temp;
  short CF=0;
  InfinityInt AbsTempThis = *this;
  InfinityInt AbsTempInf = inf;
  
  AbsTempThis.getAbsInfInt();
  AbsTempInf.getAbsInfInt();
  //AbsTempThis.print("AbsTempThis = ");
  //AbsTempInf.print("AbsTempInf = ");

  if (this->sign == inf.sign)
  { if (AbsTempThis < AbsTempInf)
    { TempMin = AbsTempThis;
      TempMax = AbsTempInf;
    }
    else
    { TempMax = AbsTempThis;
      TempMin = AbsTempInf;
    }
  
    Temp.sign = inf.sign;
    TempMin.addLeadingZeros(TempMax);
    
    //TempMax.print("TempMax = ");
    //TempMin.print("TempMin = ");
    
    TempMin.reverse();
    TempMax.reverse();
    
    //TempMax.print("TempMax = ");
    //TempMin.print("TempMin = ");
  
    for (int i=0; i<TempMax.digits.size(); i++)
    { Temp.digits.push_back(sumOfUnit(TempMax.digits[i], TempMin.digits[i], CF));
    }
  
    if (CF==1)
    { Temp.digits.push_back(CF);
    }
    
    Temp.reverse();
    Temp.removeLeadingZeros();
  }
  
  else 
  { if (AbsTempThis < AbsTempInf)
    { Temp.sign = inf.sign;
      TempMin = AbsTempThis;
      TempMax = AbsTempInf;
    }
    else
    { Temp.sign = this->sign;
      TempMax = AbsTempThis;
      TempMin = AbsTempInf;
    }
    
    TempMin.addLeadingZeros(TempMax);
    
    TempMax.reverse();
    TempMin.reverse();   
    
    for (int i=0; i<TempMax.digits.size(); i++)
    { Temp.digits.push_back(diffOfUnit(TempMax.digits[i], TempMin.digits[i], CF));
    }
    
    if (CF==1)
    { Temp.digits.push_back(CF);
    }
    
    Temp.reverse();
    Temp.removeLeadingZeros();
  }
  //cout << "Выбрали знак: " << Temp.sign << endl;
  //TempMax.print("TempMax = ");
  //TempMin.print("TempMin = ");
  return Temp;
}

// *********************************************************  operator+ число
 InfinityInt operator+(const long int a)
 { 
  InfinityInt TempA(a); 
  InfinityInt Temp = *this + TempA;
  return Temp;
 }
 
// *********************************************************  operator-
InfinityInt operator-(const InfinityInt & inf)
{
  InfinityInt Temp;
  InfinityInt AbsTempThis = *this;
  InfinityInt AbsTempInf = inf;
  short CF;
  
  AbsTempThis.getAbsInfInt();
  //AbsTempThis.print ("AbsTempThis = ");
  
  AbsTempInf.getAbsInfInt();
  //AbsTempInf.print ("AbsTempI = ");
  
  AbsTempInf.addLeadingZeros(AbsTempThis);
  //AbsTempInf.print ("AbsTempI = ");
  
  if (this->sign == inf.sign)
  {   
      // AbsTempThis.reverse();
      // AbsTempInf.reverse();
      
    if (AbsTempThis > AbsTempInf)
    { 
      //cout << "HERE" <<endl;
      Temp.sign = inf.sign;
      
      AbsTempThis.reverse();
      AbsTempInf.reverse();
      
      //AbsTempThis.print("AbsTempThis = ");
      //AbsTempInf.print("AbsTempInf = ");
      
      CF=0;
      for (int i=0; i<AbsTempThis.digits.size(); i++)
      { Temp.digits.push_back(diffOfUnit(AbsTempThis.digits[i], AbsTempInf.digits[i], CF));
      } 
    }
    else
    { 
      if (this->sign == '-')
      { Temp.sign = '+';
      }
      else
      { Temp.sign = '-';
      }
      
      CF=0;      
      for (int i=0; i<AbsTempInf.digits.size(); i++)
      { Temp.digits.push_back(diffOfUnit(AbsTempInf.digits[i], AbsTempThis.digits[i], CF));
  } } }
  
  else 
  { if (AbsTempThis > AbsTempInf)
    { Temp.sign = this->sign;
      AbsTempInf.addLeadingZeros(AbsTempThis);
      AbsTempThis.reverse();
      AbsTempInf.reverse();
      CF=0;   
      for (int i=0; i<AbsTempThis.digits.size(); i++)
      { Temp.digits.push_back(sumOfUnit(AbsTempInf.digits[i], AbsTempThis.digits[i], CF));
    } }
    else
    { Temp.sign = this->sign;
      AbsTempThis.addLeadingZeros(AbsTempInf);
      AbsTempThis.reverse();
      AbsTempInf.reverse();
      CF=0; 
      for (int i=0; i<AbsTempThis.digits.size(); i++)
      { Temp.digits.push_back(sumOfUnit(AbsTempInf.digits[i], AbsTempThis.digits[i], CF));
  } } }
    
    Temp.reverse();
    Temp.removeLeadingZeros();
    //*this = Temp;
  
  return Temp;
}

// *********************************************************  operator- число
InfinityInt operator-(const long int a)
{
  InfinityInt TempA(a);
  InfinityInt Temp = *this - TempA;

  return Temp;
}

// *********************************************************  operator*
InfinityInt operator*(const InfinityInt & inf)
{ 
  InfinityInt Temp1 = *this;
  InfinityInt Temp2 = inf;
  
  Temp1 = *this; 
  Temp2 = inf;
  
  Temp1.absInfInt(); 
  Temp2.absInfInt();
  
  short CF = 0;
  InfinityInt Res = "0";
  InfinityInt Temp;
  
  Temp1.reverse();
  Temp2.reverse();
  
  for (int j=0; j< Temp2.digits.size(); j++)
  { 
    Temp.digits.clear();
    for (int i=0; i<Temp1.digits.size(); i++) // 
    { Temp.digits.push_back(multOfUnit(Temp1.digits[i], Temp2.digits[j], CF)); 
    }
    Temp.reverse(); 
    
    for (int k=1; k<=j; k++)
    { Temp.digits.push_back(0);
    }

    if (CF != 0)
    { Temp.reverse();
      Temp.digits.push_back(CF);
      Temp.reverse();
    }
    Res = Res + Temp;
  }
  
  if (this->sign == inf.sign)
  { Res.sign = '+';
  }
  else
  { Res.sign = '-';
  }
  
  return Res;
}
// *********************************************************  operator* int
InfinityInt operator*(const long int a)
{
  InfinityInt TempA(a);
  InfinityInt Temp2 = *this;
  InfinityInt Temp = Temp2 * TempA;

  return Temp;
}
// *********************************************************  operator/
InfinityInt operator/(const InfinityInt & inf)
{ 
  InfinityInt Temp1;
  InfinityInt Temp2;
  InfinityInt Count = "0";
  
  Temp1 = *this; 
  Temp2 = inf;
  
  Temp1.absInfInt(); 
  Temp2.absInfInt();

  while (Temp1 > Temp2)
  { Temp1 = Temp1 - Temp2;
    Count++;
  }
  
  if (Temp1 == Temp2)
  { Count++;
    Temp1.digits.clear();
    Temp1.digits.push_back(0);
  } 
  
  if (this->sign == inf.sign)
  { Count.sign = '+';
  }
  else
  { Count.sign = '-';
  }
  
  return Count;
}
// *********************************************************  operator/ int
InfinityInt operator/(const long int a)
{
  InfinityInt TempA(a);
  InfinityInt Temp2 = *this;
  InfinityInt Temp = Temp2 / TempA;

  return Temp;
}

// *********************************************************  operator%
InfinityInt operator%(const InfinityInt & inf)
{ 
  InfinityInt Temp1;
  InfinityInt Temp2;
  InfinityInt Count = "0";
  
  Temp1 = *this; 
  Temp2 = inf;
 
  Temp1.absInfInt(); 
  Temp2.absInfInt();

  while (Temp1 > Temp2)
  { Temp1 = Temp1 - Temp2;
    Count++;
  }
  
  if (Temp1 == Temp2)
  { Count++;
    Temp1.digits.clear();
    Temp1.digits.push_back(0);
  }
  
  if (this->sign == inf.sign)
  { Temp1.sign = '+';
  }
  else
  { Temp1.sign = '-';
  }

  return Temp1;
}
// *********************************************************  operator% int
InfinityInt operator%(const long int a)
{
  InfinityInt TempA(a);
  InfinityInt Temp2 = *this;
  InfinityInt Temp = Temp2 % TempA;

  return Temp;
}

// *********************************************************  operator+=
InfinityInt & operator+=(const InfinityInt & inf)
{ 
  InfinityInt Temp1 = *this;
  InfinityInt Temp2 = inf;
  this->digits.clear();
  *this = Temp1 + Temp2;
  return *this;
}

// *********************************************************  operator+= long int
InfinityInt & operator+=(const long int a)
{ 
  InfinityInt Temp1 = *this;
  InfinityInt Temp2(a);
  this->digits.clear();
  *this = Temp1 + Temp2;
  return *this;
}

// *********************************************************  operator-=
InfinityInt & operator-=(const InfinityInt & inf)
{
  InfinityInt Temp1 = *this;
  InfinityInt Temp2 = inf;
  this->digits.clear();
  *this = Temp1 - Temp2;
  return *this;
}

// *********************************************************  operator-= const long int
InfinityInt & operator-=(const long int a)
{
  InfinityInt Temp1 = *this;
  InfinityInt Temp2(a);
  this->digits.clear();
  *this = Temp1 - Temp2;
  return *this;
}

// *********************************************************  operator*=
InfinityInt & operator*=(const InfinityInt & inf)
{
  InfinityInt Temp1 = *this;
  InfinityInt Temp2 = inf;
  this->digits.clear();
  *this = Temp1 * Temp2;
  return *this;
}

// *********************************************************  operator*= const long int
InfinityInt & operator*=(const long int a)
{
  InfinityInt Temp1 = *this;
  InfinityInt Temp2(a);
  this->digits.clear();
  *this = Temp1 * Temp2;
  return *this;
}

// *********************************************************  operator/=
InfinityInt & operator/=(const InfinityInt & inf)
{
  InfinityInt Temp1 = *this;
  InfinityInt Temp2 = inf;
  this->digits.clear();
  *this = Temp1 / Temp2;
  return *this;
}

// *********************************************************  operator/= const long int
InfinityInt & operator/=(const long int a)
{
  InfinityInt Temp1 = *this;
  InfinityInt Temp2(a);
  this->digits.clear();
  *this = Temp1 / Temp2;
  return *this;
}

// *********************************************************  operator%=
InfinityInt & operator%=(const InfinityInt & inf)
{
  InfinityInt Temp1 = *this;
  InfinityInt Temp2 = inf;
  this->digits.clear();
  *this = Temp1 % Temp2;
  return *this;
}

// *********************************************************  operator%=  const long int
InfinityInt & operator%=(const long int a)
{
  InfinityInt Temp1 = *this;
  InfinityInt Temp2(a);
  this->digits.clear();
  *this = Temp1 % Temp2;
  return *this;
}

// *********************************************************  operator==(const SuperLong &)
bool operator==(const InfinityInt & inf) const
{ 
  bool isEqual = false;
  
  if (this->sign == inf.sign && this->digits.size() == inf.digits.size())
  { for (int i=0; i<inf.digits.size(); i++)
    { if (this->digits[i] != inf.digits[i])
      { isEqual = false;
        break;
      }
    isEqual = true;  
  } }
  
  return isEqual;
}

// *********************************************************  operator!=(const SuperLong &)
bool operator!=(const InfinityInt & inf) const
{ 
  bool isNonEqual = true;
  
  if (this->sign == inf.sign && this->digits.size() == inf.digits.size())
  { for (int i=0; i<inf.digits.size(); i++)
    { if (this->digits[i] == inf.digits[i])
      { isNonEqual = false;
        break;
      }
    isNonEqual = true;  
  } }
  
  return isNonEqual;
}
// *********************************************************  operator>(const SuperLong &)
bool operator>(const InfinityInt & inf) const
{ 
  bool isMore = false;

  if ((this->sign == inf.sign) && (this->sign == '+'))
  { if (this->digits.size() > inf.digits.size())
    { isMore = true;
  } }
  else if ((this->sign == inf.sign) && (this->sign == '-'))
  { if (this->digits.size() < inf.digits.size())
    { isMore = true;
  } }
  
  if ((this->sign == '+') && (inf.sign == '-'))
  { isMore = true;
  }
  
  if ((this->sign == '+') && (this->sign == inf.sign) && this->digits.size() == inf.digits.size())
  { for (int i=0; i<inf.digits.size(); i++)
    { if (this->digits[i] > inf.digits[i])
      { isMore = true;
        break;
  } } }
  
  if ((this->sign == '-') && (this->sign == inf.sign) && this->digits.size() == inf.digits.size())
  { for (int i=0; i<inf.digits.size(); i++)
    { if (this->digits[i] < inf.digits[i])
      { isMore = true;
        break;
  } } }
  
  return isMore;
}

// *********************************************************  operator<(const SuperLong &)
bool operator<(const InfinityInt & inf) const
{ 
  bool isLess;
  
  if ((this->sign == inf.sign) && (this->sign == '+'))
  { if (this->digits.size() < inf.digits.size())
    { isLess = true;
  } }
  else if ((this->sign == inf.sign) && (this->sign == '-'))
  { if (this->digits.size() > inf.digits.size())
    { isLess = true;
  } }
  
  if ((this->sign == '-') && (inf.sign == '+'))
  { isLess = true;
  }
  
  if ((this->sign == '+') && (this->sign == inf.sign) && this->digits.size() == inf.digits.size())
  { for (int i=0; i<inf.digits.size(); i++)
    { if (this->digits[i] < inf.digits[i])
      { isLess = true;
        break;
  } } }
  
  if ((this->sign == '-') && (this->sign == inf.sign) && this->digits.size() == inf.digits.size())
  { for (int i=0; i<inf.digits.size(); i++)
    { if (this->digits[i] > inf.digits[i])
      { isLess = true;
        break;
  } } } 
  return isLess; 
}

// *********************************************************  operator>=(const SuperLong &)
bool operator>=(const InfinityInt & inf) const
{ 
  bool isMoreEqual = false;

  if ((this->sign == inf.sign) && (this->sign == '+'))
  { if (this->digits.size() >= inf.digits.size())
    { isMoreEqual = true;
  } }
  else if ((this->sign == inf.sign) && (this->sign == '-'))
  { if (this->digits.size() <= inf.digits.size())
    { isMoreEqual = true;
  } }
  
  if ((this->sign == '+') && (inf.sign == '-'))
  { isMoreEqual = true;
  }
  
  if ((this->sign == '+') && (this->sign == inf.sign) && this->digits.size() == inf.digits.size())
  { for (int i=0; i<inf.digits.size(); i++)
    { if (this->digits[i] >= inf.digits[i])
      { isMoreEqual = true;
        break;
  } } }
  
  if ((this->sign == '-') && (this->sign == inf.sign) && this->digits.size() == inf.digits.size())
  { for (int i=0; i<inf.digits.size(); i++)
    { if (this->digits[i] <= inf.digits[i])
      { isMoreEqual = true;
        break;
  } } }
  
  return isMoreEqual;
}

// *********************************************************  operator<=(const SuperLong &)
bool operator<=(const InfinityInt & inf) const
{ 
  bool isLessEqual;
  
  if ((this->sign == inf.sign) && (this->sign == '+'))
  { if (this->digits.size() <= inf.digits.size())
    { isLessEqual = true;
  } }
  else if ((this->sign == inf.sign) && (this->sign == '-'))
  { if (this->digits.size() >= inf.digits.size())
    { isLessEqual = true;
  } }
  
  if ((this->sign == '-') && (inf.sign == '+'))
  { isLessEqual = true;
  }
  
  if ((this->sign == '+') && (this->sign == inf.sign) && this->digits.size() == inf.digits.size())
  { for (int i=0; i<inf.digits.size(); i++)
    { if (this->digits[i] <= inf.digits[i])
      { isLessEqual = true;
        break;
  } } }
  
  if ((this->sign == '-') && (this->sign == inf.sign) && this->digits.size() == inf.digits.size())
  { for (int i=0; i<inf.digits.size(); i++)
    { if (this->digits[i] >= inf.digits[i])
      { isLessEqual = true;
        break;
  } } } 
  return isLessEqual; 
}

// *********************************************************  operator++ pre
InfinityInt & operator++()
{ *this = *this + 1;
  return *this;
}
// *********************************************************  operator++ post
InfinityInt operator++(int a)
{ InfinityInt Temp = *this;
  *this = *this + 1;
  return Temp;
}
// *********************************************************  operator-- pre
InfinityInt & operator--()
{ 
  *this = *this - 1;
  return *this;
}
// *********************************************************  operator-- post
InfinityInt operator--(int)
{ 
  InfinityInt Temp = *this;
  *this = *this - 1;
  return Temp;
}

// ***************************************************************************************
// ******************************************************************** Add functions ****
// ***************************************************************************************

//*******************************************************   print InfinityInt
void print(const string note) const
{ 
  cout << note ;
  
  if (sign == '-')
  { cout << sign ;
  }
  else
  { cout << ' ';
  }
  
  for (int i=0; i<digits.size(); i++)
  { cout << digits[i];
  } 
  cout << endl;
}

private:
// *******************************************************  sumOfUnit
short sumOfUnit(const char a, const char b, short & refCF)
{ short sum;
  sum = (a + b + refCF) % 10;
  refCF = (a + b + refCF) / 10;
  return sum;
}

// *******************************************************  diffOfUnit
short diffOfUnit(const char a, const char b, short & refCF)
{
  short diff;

  if (a>=b)
  { diff = ((a-refCF) - b);
    refCF = 0;
  }
  
  else if (a<b)
  { 
    if ((a == 0) && (refCF == 1))
    { diff = (9 - b);
      refCF = 1;    
    }
    else
    { diff = ((10 - refCF + a) - b);
      refCF = 1;
    }
  } 
  return diff;
}


// ****************************************************  multOfUnit
public:
short multOfUnit(const short a, const short b, short & refCF)
{  
  short mult = a * b + refCF;
  
  //cout << "mult = " << mult << endl;
  refCF = mult / 10;
  mult = mult % 10;
  //cout << "mult = " << mult << endl;
  //cout << "refCF = " << refCF << endl;
  return mult;
}

// ****************************************************** addLeadingZeros
InfinityInt & addLeadingZeros(const InfinityInt & inf)
{ 
  //int tt;
  InfinityInt Temp;
  
  for (int i=0; i<(inf.digits.size() - this->digits.size()); i++)
  { Temp.digits.push_back(0); 
  }
  
  for (int i=0; i<(this->digits.size()); i++)
  { Temp.digits.push_back(this->digits[i]); 
  }
  
  this->digits.clear();
  
  for (int i=0; i<Temp.digits.size(); i++)
  { this->digits.push_back(Temp.digits[i]);
  }
  
  return *this;
}

// ****************************************************** removeLeadingZeros
InfinityInt & removeLeadingZeros()
{ 
  while (this->digits[0] == 0)
  {digits.erase(digits.begin());
  }
  return *this;
}

//***************************************************************  reverse
InfinityInt & reverse()
{ InfinityInt Temp = (*this);
  this->digits.clear();
  for (int i = 0; i < Temp.digits.size(); i++)
  { digits.push_back(Temp.digits[Temp.digits.size()-i-1]);
  }
  return *this;
}
// **************************************************************  absInfInt
InfinityInt & absInfInt()
{ this->sign = '+';
  return *this;
}

// **************************************************************  getAbsInfInt
InfinityInt & getAbsInfInt()
{ 
  InfinityInt Temp = *this;
  Temp.sign = '+';
  this->digits.clear();
  *this = Temp;
  return *this;
}

// *************************************************************  END

}; 
