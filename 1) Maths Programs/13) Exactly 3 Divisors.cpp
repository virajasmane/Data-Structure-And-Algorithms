/*Given a positive integer value N. The task is to find how many numbers less
than or equal to N have numbers of divisors exactly equal to 3.*/
#include <bits/stdc++.h>
using namespace std;

int exactly3Div(int N)//Naive soultion doesn't work for larger no. TLE error
{
  int ans=0;
  for(int j=1; j<=N; j++)
  {
    int count=0;
    for(int i=1; i*i<=j; i++)
    {
      if(j%i==0)
      {
        count++;
        if(i!=j/i)
          count++;
      }
    }
    if(count == 3)
        ans++;
    }
    return ans;
}
//______________________________________________________________________________

/*If a number's sqrtroot is a prime number then the number will have exactly 3
  divisiors.  */

bool isPrime(int a)
{
    if(a==1)
      return false;
    if(a==2 || a==3)
      return true;
    if(a%2==0 || a%3==0)
      return false;
    for(int i=5; i*i<=a; i+=6)
      if(a%i==0 || a%(i+2)==0)
        return false;
    return true;
}
int exactly3Divisors(int N)
{
  int ans=0;
  for(int i=2; i*i<=N; i++) // sqrt(n) time.
  {
    if(isPrime(i)) // sqrt(n) time.
      ans++;
  }
  return ans;
  //Time Complexity :- BigO(n)
  //Space Complexity :- Theta(1)
}


int main()
{
  int N;
  cout<<"Enter n \n";
  cin>>N;
  cout<<exactly3Divisors(N);
	return 0;
}
