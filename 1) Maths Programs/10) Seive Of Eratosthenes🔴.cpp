#include <bits/stdc++.h>
using namespace std;

//Question :- Print all the prime nos upto n.

bool isprime(int n)
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
void printprime(int n) //Naive solution
{
  for(int i=1; i<n; i++) // Theta(n)
  {
    if(isprime(i))  // BigO( sqrt(n) )
      cout<<i<<endl;
  }
  //Time complexity :- BigO( n*sqrt(n) )
}
//_____________________________________________________________________________

//Seive of eratosthenes simple implementation
void seive(int n)
{
  vector<bool> isprime(n+1, true);
  for(int i=2; i*i<=n; i++)        // DIVISORS ALWAYS APPEARS IN PAIRS
    if(isprime[i])
      for(int j=2*i; j<=n; j+=i)
        isprime[j]=false;
  for(int i=2; i<=n; i++)
    if(isprime[i])
      cout<<i<<endl;
}
//_____________________________________________________________________________

//Optimized implementation
/* *** sqr(i), sqr(i)+i, sqr(i)+2i, sqr(i)+3i, ......
   Earlier 5 : 10, 15, 20, 25, 30, ...
   Now     5 : 25, 30, ....
   Composite number smaller than sqr(i)
    i*(i-1)
    i*(i-2)
       .
       .
       .
    So they have smaller divisor (i-1) and (i-2) which are already considered.
    For eg, in Earlier 10, 15, 20 have a smaller divisor than 5 which are 2 and 3
    so we don't consider them.*/
void aseive(int n)
{
  vector<bool> isprime(n+1, true);
  for(int i=2; i*i<=n; i++)
    if(isprime[i])
      for(int j=i*i; j<=n; j+=i) //***Only difference is instead of 2*i its i*i
        isprime[j]=false;
  for(int i=2; i<=n; i++)
    if(isprime[i])
      cout<<i<<endl;
      //Time Complexity :- BigO( n * Log(Log(n)) )
}
//_____________________________________________________________________________

/*Shorter implementation of the seive time complexity wise same as the above
  but code length is shorter. */
void bseive(int n)
{
  vector<bool> isprime(n+1, true);
  for(int i=2; i<=n; i++) // Here we dont use i*i<=n because in the j for loop
    if(isprime[i])       //the first condition j=i*i so it won't enter the
      {                 //loop for values more than sqrt(n) which was our
        cout<<i<<endl;  // aim to put i*i<=n in the first for loop.
        for(int j=i*i; j<=n; j+=i)//So now we can print i in the same loop.
          isprime[j]=false;
      }
  //Time complexity :- BigO( n*log(log(n)) ) which is better than n*sqrt(n)
}



int main()
{
  int n;
  cout<<"Enter n \n";
  cin>>n;
  seive(n);
	return 0;
}
