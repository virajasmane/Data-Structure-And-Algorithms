// Input: N = 4
// Output: 7
// Explanation: 4 is represented as 100 in
// binary form. The binary code of 100 is 111,
// in the binary form whose decimal equivalent
// is 7.

#include <bits/stdc++.h>
using namespace std;

int GtoBConverter(int n)
{
  int res = n;
  while(n>0)
  {
      n >>= 1;
      res ^= n;
  }
  return res;
}


int main()
{
  int n;
  cout<<"Enter a number\n";
  cin>>n;
  cout<<GtoBConverter(n);
	return 0;
}
