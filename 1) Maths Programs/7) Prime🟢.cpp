// 1 is neither prime nor composite.
//True = 1  False = 0
#include <bits/stdc++.h>
using namespace std;


bool isprime(int n) //Naive Solution
{
  if(n==1)
    return false;
  for(int i=2; i<n; i++)
    if(n%i==0)
      return false;
  return true;
  // Time Complexity :-  BigO(n)
}
//___________________________________________________________________________

//Efficient Solution Logic
/* 30 : (1,30), (2,15), (3,10), (5,6)
   65 : (1,65), (5,13)
   25 : (1,25), (5,5)
   If (x,y) is a pair implies x*y = n (As shown above)
   and if x <= y
          x*x <=n
          x <= sqrt(n)
   So we don't have to run the loop from i=2 to i=n-1 we've to only
   run it till i=sqrt(n) because even if there is a divisor higher than sqrt(n)
   it must have a pair and we must have found that pair.
   So Time Complexity will be BigO( Sqrt(n) ) */
bool aisprime(int n) //Efficient Solution
{
  if(n==1)
    return false;
  for(int i=2; i*i<=n; i++)
    if(n%i==0)
      return false;
  return true;
}
//___________________________________________________________________________

//Most efficient solution for larger numbers.
/* The logic for larger number is to check 1st if the number is divisible
by 2 || 3 or not. and if it is not then we can skip checking the multiples
of 2 and 3 which will save us a lot of iterations, it is around 3x faster
than the above efficient solution.
eg n = 121  i = 5, i = 11
   n = 1031 i = 5, i = 11, i = 17, i = 23, i = 29 */
bool bisprime(int n)
{
  if(n==1)
    return false;
  if(n==2 || n==3)
    return true;
  if(n%2==0 || n%3==0)
    return false;
  for(int i=5; i*i<=n; i+=6)
    if(n%i==0 || n%(i+2)==0)
      return false;
  return true;
}

int main()
{
  int n;
  cout<<"Enter n \n";
  cin>>n;
  cout<<bisprime(n);
	return 0;
}
