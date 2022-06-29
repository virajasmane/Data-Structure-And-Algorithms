#include <bits/stdc++.h>
using namespace std;

int sumofdigits(int n)
{
  if(n==0)
    return 0;
  return n%10 + sumofdigits(n/10);
  // Time Complexity :- Theta( No of digits in n )
  // Auxillary Space :- Theta( No of digits in n )
}

int main()
{
  int n;
  cout<<"Enter the value of n\n";
  cin>>n;
  cout<<sumofdigits(n);
	return 0;
}
