#include <bits/stdc++.h>
using namespace std;

unsigned int swapBits(unsigned int n)
{
  int even = (n & 0xAAAAAAAA);
  even >>= 1;
  int odd = (n & 0x55555555);
  odd <<= 1;
  return (even | odd);
}

int main()
{
  int n;
  cout<<"Enter a number\n";
  cin>>n;
  cout<<swapBits(n);
	return 0;
}
