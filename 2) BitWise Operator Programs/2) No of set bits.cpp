#include <bits/stdc++.h>
using namespace std;

void isSet(int n) // Naive solution
{
  int res = 0;
  while(n>0)
  {
    res += (n&1);
    n >>= 1;
  }
  cout<<res;
  // Time Complexity :- Theta(total bits in n)
}
//______________________________________________________________________________

// Brain Kerningam's Algorithm
// In a binary number when n is AND(&) with n-1 the last set bit of n from RHS
// gets reset.
void isSetB(int n)
{
  int res = 0;
  while(n>0)
  {
    n &= (n-1);
    res++;
  }
  cout<<res;
  // Time Complexity :- Theta( Set bit count )
}
//______________________________________________________________________________

//Lookup table method (for 32 bits number).

int table[256];

void initialize()
{
  table[0]=0;
  for(int i=1; i<256; i++)
    table[i] = (i&1) + table[i/2];
}

void isSetA(int n)
{
  initialize();

  int res = table[n & 0xff];
  n >>= 8;

  res += table[n & 0xff];
  n >>= 8;

  res += table[n & 0xff];
  n >>= 8;

  res += table[n & 0xff];

  cout<<res;
}

int main()
{
  int n;
  cout<<"Enter n\n";
  cin>>n;
  isSetA(n);
	return 0;
}
