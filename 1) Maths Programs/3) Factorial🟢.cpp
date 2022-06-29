#include <bits/stdc++.h>
using namespace std;

int fact(int n) // Iterative Function
{
  int f = 1;
  for(int i=1;i<=n;i++)
    f = f* i;
  return f;
  // Time Complexity :- Theta(n)
  // Auxiliary Space :- Theta(1)
}
//___________________________________________________________________________

int rfact(int n) // Recursive Function
{
  if(n<1)
    return 1;
  return n * rfact(n-1);
  // Time Complexity :- Theta(n)
  // Auxiliary Space :- Theta(n)
}

int main()
{
  int n;
  cout<<"Enter n \n";
  cin>>n;
  cout<<rfact(n);
	return 0;
}
