// Amazon, Microsoft, Walmart Question

#include <bits/stdc++.h>
using namespace std;

josh(int n, int k)
{
  if(n==1)
    return 0;
  else
    return ((josh(n-1,k)+k)%n);
  // Time Complexity :- Theta(n)
}

int main()
{
  int n,k;
  cout<<"Enter the value of n and k\n";
  cin>>n>>k;
  cout<<josh(n,k);
	return 0;
}
