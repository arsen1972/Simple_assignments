#include <iostream>
#include "Class_InfinityInt.cpp"

using namespace std;

int main()
{try
{ 
  InfinityInt A = "-33333";
  A.print("A = ");  
  
  InfinityInt B = "11111";
  B.print("B = ");
  
  InfinityInt C;
  C = A + B;
  C.print("C = A + B  -> \t");
  
  InfinityInt D;
  D = A - B;
  D.print("C = A - B  -> \t");
  
  InfinityInt E;
  E = A * B;
  E.print("E = A * B  -> \t");
  
  InfinityInt F;
  F = A / B;
  F.print("F = A / B  -> \t");
  
  C = B++;
  C.print("C = B++ -> ");
  B.print("B++ = ");
  
  C = B--;
  C.print("C = B-- -> ");
  B.print("B-- = ");
  
  C = ++B;
  C.print("C = ++B -> ");
  B.print("++B = ");
  
  C = --B;
  C.print("C = --B -> ");
  B.print("--B = ");
  
  C = A + 555;
  C.print("C = A + 555  -> \t");
  
  C = A - 111;
  C.print("C = A - 111  -> \t");
  
  C = A * 2;
  C.print("C = A * 2  -> \t");
  
  C = A / 3;
  C.print("C = A / 3  -> \t");
  
  C += 555;
  C.print("C += 555  -> \t");
  
  C -= 111;
  C.print("C -= 111  -> \t");
  
  C *= 2;
  C.print("C *= 2  -> \t");
  
  C /= 3;
  C.print("C /= 3  -> \t");
  
  cout << "A == B   -> \t" << (A==B) << endl; 
  cout << "A != B   -> \t" << (A!=B) << endl;
  cout << "A > B   -> \t" << (A>B) << endl; 
  cout << "A < B   -> \t" << (A<B) << endl; 
  cout << "A >= B   -> \t" << (A>=B) << endl; 
  cout << "A <= B   -> \t" << (A<=B) << endl; 
   
  
  
//  InfinityInt C = "33"; 
//  C.print("C = ");
  
//  InfinityInt D = B / C;
//  D.print("D = B / C  -> ");
  
//  InfinityInt E = B % C;
//  E.print("E = B $ C  -> ");

//  InfinityInt D = B * 33;
//  D.print("D = B * 33  -> ");
  
//  B.print("B = ");
  
//  InfinityInt E = B + 555 + B;
//  E.print("E = B + 555 + B  -> ");
  
//  InfinityInt E = B + C + B;
//  E.print("E = B + B  -> ");
  
  
//  int b = -555;
//  cout << "b = " << b <<endl;
  
//  B - b;
//  B.print("B = B - b  -> ");
//  B * C;
//  B.print("B = B * C  -> ");

//  InfinityInt D = B * C;
//  D.print("D = B * C  -> ");
  
//  int b = 123456;
//  cout << "b = " << b << endl;
  
//  B = B + C;
//  B.print("B = B + C  ");
  
//  for (int i = 0; i < 10; i++)
//  {
//  --B;
//  B.print("--B  = ");
//  }
//  InfinityInt Bm = "-123456789"; 
//  Bm.print("Bm = ");
 



//  C += B;
//  C.print("C += B ");
/*
  short b = 215;
  cout << "b = " << b << endl;
  
  for (int i=0; i<10; i++)
  {
  ++B;
  B.print("++B =\t");
  }
  cout << "b =\t" << "  " << b << endl;
  B + b;
  B.print("B + b =\t");

  InfinityInt Cm = -12345; 
  Cm.print("Cm = ");
  
  InfinityInt D = B; 
  D.print("D(B) = ");
  
  InfinityInt D1(Bm); 
  D1.print("D1(Bm) = ");
  
  InfinityInt Dcopy;
  Dcopy = Cm;
  Dcopy.print("Dcopy = Cm = ");
  
  cout << endl;
  cout << "B > C ?  " << (B > C) << endl;
  cout << "C > B ?  " << (C > B) << endl;
  cout << "C == B ?  " << (C == B) << endl;
  
  cout << "Bm > Cm ?  " << (Bm > Cm) << endl;
  cout << "Cm > Bm ?  " << (Cm > Bm) << endl;
  cout << "Cm == Bm ?  " << (Cm == Bm) << endl;
  
  cout << "B < C ?  " << (B < C) << endl;
  cout << "C < B ?  " << (C < B) << endl;
  cout << "C == B ?  " << (C == B) << endl;
  
  cout << "Bm <= Cm ?  " << (Bm <= Cm) << endl;
  cout << "Cm <= Bm ?  " << (Cm <= Bm) << endl;
  cout << "Cm == Bm ?  " << (Cm == Bm) << endl;
  
  cout << "B <= C ?  " << (B <= C) << endl;
  cout << "C <= B ?  " << (C <= B) << endl;
  cout << "C == B ?  " << (C == B) << endl;
  
  cout << "Bm <= Cm ?  " << (Bm <= Cm) << endl;
  cout << "Cm <= Bm ?  " << (Cm <= Bm) << endl;
  cout << "Cm == Bm ?  " << (Cm == Bm) << endl;
   
  cout << "\nB == Bm ?  " << (B == Bm) << endl;
  cout << "B != Bm ?  " << (B != Bm) << endl;
  
  cout << "D1 == Bm ?  " << (D1 == Bm) <<endl;
  cout << "D1 != Bm ?  " << (D1 != Bm) << endl;
  
  cout << "C == Cm  ?  " << (C == Cm) << endl;
  cout << "C != Cm  ?  " << (C != Cm) << endl;
  
  cout << "C == C  ?  " << (C == C) << endl;
  cout << "C != C  ?  " << (C != C) << endl;
*/  
}
  
  catch (int)
     { cout << "Input noncorrect" << endl;}
    
  catch (...)
     { cout << "Плохо все и не понятно что именно!" << endl;}    
     
  return 0;
}