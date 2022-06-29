#include <bits/stdc++.h>
using namespace std;

// I/P :- x=2, n=3
//O/P :- 8
//Compute x^n

int computepow(int x, int n) //Naive solution
{
  int res = 1;
  for(int i=0; i<n; i++)
    res *= x;
  return res;
  //Time Complexity :- Theta(n)
}
//______________________________________________________________________________

// Recursive solution
//Logic    if n is even then (x raiseto n/2) * (x raiseto n/2)
//         if n is odd then  (x raiseto n-1) * x
int rcomputepow(int x, int n)
{
  if(n==0)
    return 1;
  int temp = rcomputepow(x,n/2);
  temp *= temp;
  if(n%2==0)
    return temp;
  else
    return temp*x;

//Time Complexity :- T(n) = T(n/2) + Theta(1)
// SO if we make a tree the time Complexity will come out to be Theta( log(n) )
//Aux Space :- Theta( log(n) ) because height is log(n)
}
//______________________________________________________________________________

// Now will write an iterative solution to reduce Aux space to BigO(1)
// and the Time Complexity will remain same ie BigO( log(n) )
//     Binary Exponentiation
/* Two main points for this solution
  1) Every number can be written as sum of powers of 2 (Set bits in Binary
     representation).
     eg 3^10 =  (3^8) x (3^2)
     10 : 1010

  2) We can traverse through all the bits of a number(from LSB To MSB) in
     BigO( log(n) ) time. */
int icomputepow(int x, int n)
{
  int res = 1;
  while(n>0)
  {
    if(n%2!=0) //for better solution can use bitwise AND op here if(n&1)
      res *= x;
    x *= x;
    n /= 2; //for better solution can use rightshift operator n = n>>1;
  }        // it means we are dividing by n by 2 raiseto 1.
  return res;
}

//______________________________________________________________________________
// MakeMyTrip, Walmart Question

// When input is large and we've to get the output in %(10^9+7)


const int A = 1000000007;
long long power(int x, int n)
{
  if(n==0)
    return 1;
  long temp = power(x, n/2);
  temp = (temp*temp)%A;
  if(n%2==0)
    return temp;
  else
    return (x*temp)%A;
}

int main()
{
  int x,n;
  cout<<"Enter x and n \n";
  cin>>x>>n;
  cout<<icomputepow(x,n);
	return 0;
}
