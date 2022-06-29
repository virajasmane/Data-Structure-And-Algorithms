// MODULAR MULTIPLICATIVE INVERSE (MMI)
// Given two integers a and m, MMI x is a.x = 1 (mod m) where x E 1 to m-1
// MMI exists if a and m are coprime ie gcd(a,m) = 1.

#include <bits/stdc++.h>
using namespace std;

int mmi(int a, int m) //Naive solution
{
  for(int i=1; i<m; i++)
  {
    if((a*i)%m==1)
      return i;
  }
  return -1;
  // Time Complexity :- BigO(m)
}

//______________________________________________________________________________

// Using Extended Euclidean Algorithm

// GFG Link :- https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/


int EEA(int a, int m, int *x, int *y);

void mmi1(int a, int m)// Function to find mmi
{
  int x, y;
  int g = EEA(a, m, &x, &y);
  if(g!=1)
    cout<<"Modular Multiplicative Inverse doesn't exists. ";
  else
    cout<<x<<"\n";
}


int EEA(int a, int m, int *x, int *y)
{
  if(a==0)
    {
      *x=0;
      *y=1;
      return m;
    }
  int x1, y1;
  int g = EEA(m%a, a, &x1, &y1);

  *x = y1 - (m/a) * x1;
  *y = x1;
  return g;
  // Time Complexity :- BigO( Log(m) )
}




int main()
{
  int a,m;
  cout<<"Enter a and b \n";
  cin>>a>>m;
  cout<<mmi(a,m)<<endl;
  mmi1(a,m);
	return 0;
}
