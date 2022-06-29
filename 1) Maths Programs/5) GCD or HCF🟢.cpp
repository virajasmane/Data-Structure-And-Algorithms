#include <bits/stdc++.h>
using namespace std;

// Divisor of a no is a no which evenly divides that no.
// GCD/HCF will be smaller than or equal to smallest of the given 2 nos.
int gcd(int a, int b) //Naive Solution
{
  int n = min(a,b);
  while(n>0)
  {
    if(a%n==0 && b%n==0)
      break;
    n--;
  }
  return n;
  // Time Complexity :- BigO( min(a,b) )
}
//___________________________________________________________________________

int ngcd(int a, int b) //Euclidean Algorithm
{
  while(a!=b)
  {
    if(a>b)
      a -= b;
    else
      b -= a;
  }
  return a; //Or return b doesnt matter coz both are same.
}
//___________________________________________________________________________

int agcd(int a, int b) //  Optimized Euclidean Algorithm
{
  if(b==0)
    return a;
  else
    return agcd(b,a%b);
    // Time Complexity :- BigO( log(min(a,b)) )
    // Since we are reducing b to 0, no of steps required to reduce b to 0 is
    // the time complexity.
}


int main()
{
  int a,b;
  cout<<"Enter a and b \n";
  cin>>a>>b;
  cout<<agcd(a,b);
	return 0;
}
