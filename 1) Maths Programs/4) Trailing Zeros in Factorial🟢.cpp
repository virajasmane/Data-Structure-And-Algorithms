#include <bits/stdc++.h>
using namespace std;

int fact(int n) // Naive Solution
{
  long long int f = 1, count = 0;
  for(int i=1 ; i<=n ; i++)
    f = f* i;
  while(f % 10 == 0)
  {
    count++;
    f /= 10;
  }
  return count;
  // Time Complexity :- Theta (n)
}
//_____________________________________________________________________

// Effecient Solution
/*Each 2 x 5 makes a 10 so every 2 x 5 adds a zero, in a factorial there
 will be more 2s than 5s, so in factorial every 5th number will have 5 as
 a prime factor we count that and print it
 eg 5 has one 5 so the count ie the answer will be 1
 eg 10, 1 2 3 4 5 6 7 8 9 10 here 5 and 10 have 5 as a factor so count is 2
 so first we divide the numbers by 5 then by 25 then 125 untill the numbers
 is less than equal to n.
 formula is floor(n/5) + floor(n/25) + floor(n/125) + ..... */
int nfact(int n)
{
  int count = 0;
  for(int i=5; i<=n; i*=5)
    count += n/i;
  return count;
  //Time Complexity :- Theta(log n)
}

int main()
{
  int n;
  cout<<"Enter n \n";
  cin>>n;
  cout<<nfact(n);
	return 0;
}
