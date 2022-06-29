#include <bits/stdc++.h>
using namespace std;

// 5 x 4 = 20, 20 is multiple of 5 and 4
//             5 and 4 are factors of 20


int lcm(int a, int b) //Naive Solution
{
  int res = max(a,b);
  while(true)
  {
    if(res%a==0  && res%b==0)
      return res;
    res++;
  }
  // Time Complexity :- BigO( a*b - max(a,b) )
}
//___________________________________________________________________________

//  Optimized Solution based on FORMULA
//  FORMULA  -->  a*b = gcd(a,b) * lcm(a,b)
int gcd(int a, int b)
{
  if(b==0)
    return a;
  else
    return gcd(b,a%b);
}
int alcm(int a, int b)
{
  return a*b/gcd(a,b);
  // Time Complexity :- BigO( log(min(a,b)) )
}

int main()
{
  int a,b;
  cout<<"Enter a and b \n";
  cin>>a>>b;
  cout<<alcm(a,b);
	return 0;
}
