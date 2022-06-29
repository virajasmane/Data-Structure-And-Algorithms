// Input: N = 7
// Output: 4
// Explanation: 7 is represented as 111 in
// binary form. The gray code of 111 is 100,
// in the binary form whose decimal equivalent
// is 4.

#include <bits/stdc++.h>
using namespace std;

int BtoGConverter(int n)
{
    return n^(n>>1);
}


int main()
{
  int n;
  cout<<"Enter a number\n";
  cin>>n;
  cout<<BtoGConverter(n);
	return 0;
}
