#include <bits/stdc++.h>
using namespace std;

//If a number is not prime then one of its divisor(which is a prime factor) must be in
//this range (1 to sqrt(n)).
//Ans if there is no divisor(which is a prime factor) in this range then that number is
//a PRIME NUMBER. 

// I/P :- 10
// O/P :- 1 2 5 10

void divisors(int n) //Naive solution
{
  for(int i=1; i<=n; i++)
  {
    if(n%i==0)
      cout<<i<<endl;
  }
  //Time complexity :- Theta(n)
  //Aux Space :- Theta(1)
}
//____________________________________________________________________________

// Effecient solution
/* 30 : (1,30), (2,15), (3,10), (5,6)
   65 : (1,65), (5,13)
   25 : (1,25), (5,5)
   If (x,y) is a pair implies x*y = n (As shown above)
   and if x <= y
          x*x <=n
          x <= sqrt(n) */
void adivisors(int n)
{
  for(int i=1; i*i<=n; i++)    // DIVISORS ALWAYS APPEARS IN PAIRS
  {
    if(n%i==0)
    {
      cout<<i<<endl;
      if(i!=n/i)
        cout<<n/i<<endl;
    }
  }
  //Time complexity :- Theta( sqrt(n) )
  //Aux Space :- Theta(1)
}
//____________________________________________________________________________

//But the above solution doesn't print the divisors in increasing order so
//the below solution prints the no in order preserving its Time complexity
void bdivisors(int n)
{
  int i;
  for(i=1; i*i<n; i++)
  {
    if(n%i==0)
      cout<<i<<endl;
  }
  for( ; i>=1; i--)
  {
    if(n%i==0)
      cout<<n/i<<endl;
  }
}

int main()
{
  int n;
  cout<<"Enter n \n";
  cin>>n;
  divisors(n);
	return 0;
}
