#include <bits/stdc++.h>
using namespace std;

// 5 x 4 = 20, 20 is multiple of 5 and 4
//             5 and 4 are factors of 20
//True = 1  False = 0

// I/P :- 8
// O/P :- 2 2 2
// I/P :- 10
// O/P :- 2 5

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
void primefac(int n) //Naive Solution
{
  for(int i=2; i<n; i++) //This loops takes BigO(n) time
  {
    if(isprime(i)) //This takes BigO( Sqrt(n) ) time
    {
      int x = i;
      while(n%x==0)
      {
        cout<<i<<endl;
        x *= i;       //Here x can go upto n and it multiples itself with i
      }              //so it takes BigO( log(n) ) time
    }
  }
  // Time Complexity :- BigO( n * Sqrt(n) * log(n) )
}
//___________________________________________________________________________

//Effecient Solution
/*The Logic of Effecient Solution has two main points viz
  1) Divisors always appear in pairs, the same logic used in Effecient
     Solution of Prime number function (refer that)
     so we just have to run the loop till sqrt(n)
     because if a no is not a prime no then it's 1st prime factor is going to
     be present from 2 to sqrt(n).
  2) A number n can be written as multiplications of powers of prime factors
     12 = square(2) * 3
     450 = 2 * square(3) * square(5)
     13 = 13   */
void aprimefac(int n)
{
  if(n<=1)
    return;
  for(int i=2; i*i<=n; i++)
  {
    while(n%i==0)
    {
      cout<<i<<endl;
      n /= i;
    }
  }
  if(n>1)           // For corner case, the last largest prime factor which is
    cout<<n<<endl; // a prime no and would not go in the above loop.
}
//___________________________________________________________________________

//Most efficient solution for number.
/* The logic for larger number is to check if 2 and 3 are prime factors
explicitly so that we dont have to check for it multiples and significantly
reduce the number of iterations, it is around 3x faster
than the above efficient solution.*/
void bprimefac(int n)
{
  if(n<=1)
    return;
  while(n%2==0)
  {
    cout<<"2"<<endl;
    n /= 2;
  }
  while(n%3==0)
  {
    cout<<"3"<<endl;
    n /= 3;
  }
  for(int i=5; i*i<=n; i+=6)
  {
    while(n%i==0)
    {
      cout<<i<<endl;
      n /= i;
    }
    while(n%(i+2)==0)
    {
      cout<<i+2<<endl;
      n /= (i+2);
    }
  }
  if(n>3)    //Now it is not >1 but >3 because 2 and 3 prime factors are
    cout<<n<<endl; // already handled explicitly so the prime factor must be
                  // greater than 3.

  //Time complexity :- Worst case Theta( sqrt(n) )
}

int main()
{
  int n;
  cout<<"Enter n \n";
  cin>>n;
  primefac(n);
	return 0;
}
