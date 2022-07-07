#include <bits/stdc++.h>
using namespace std;

//Check if the number is power of two.

bool isPow2(int n)// Naive Solution
{
  if(n==0)
    return false;
  while(n!=1)
  {
    if(n%2 != 0)
      return false;
    n /= 2;
  }
  return true;
}

// Time Complexity :- O(log(n))

//______________________________________________________________________________

//Efficient solution (Brain Kerningham Algorithm)
//If a no is pow of 2 it will only have 1 set bit.

bool isPow2B(int n)
{
    return (  (n!=0) && ( (n & (n-1) )  == 0) );
}

// Time Complexity :- O(1)

int main()
{
  int n;
  cout<<"Enter n\n";
  cin>>n;
  cout<<isPow2B(n);

	return 0;
}
