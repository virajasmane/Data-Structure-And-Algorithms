#include <bits/stdc++.h>
using namespace std;

int printNto1(int n)
{
  if(n==0)
    return 0;
  cout<<n<<"\n";
  printNto1(n-1);
  // Time Complexity :- Theta(n)
  // Auxillary Space :- Theta(n)
}

int main()
{
  int n;
  cout<<"Enter the value of n.\n";
  cin>>n;
  printNto1(n);
	return 0;
}
