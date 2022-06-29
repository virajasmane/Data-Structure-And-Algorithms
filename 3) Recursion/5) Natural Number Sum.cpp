#include <bits/stdc++.h>
using namespace std;

int sum(int n) // Non Tail-Recursive Function
{
  if(n==1)
    return 1;
  return n+sum(n-1);
  // Time Complexity :- Theta(n)
  // Space Complexity :- Theta(n)
}

int sum(int n, int k) // Tail-Recursive Function
{
  if(n==1)
    return k;
  return sum(n-1,k+n);
  // Time Complexity :- Theta(n)
  // Space Complexity :- Theta(n)
}


int main()
{
  int n;
  cout<<"Enter the value of n.\n";
  cin>>n;
  cout<<sum(n,1);
	return 0;
}
