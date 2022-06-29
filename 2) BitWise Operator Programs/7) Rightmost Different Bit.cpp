#include <bits/stdc++.h>
using namespace std;

int posOfRightMostDiffBit(int m, int n)
{
    return (log2((m^n) & ~((m^n)-1))+1);
}

int main()
{
  int n;
  cout<<"Enter a number\n";
  cin>>n;
  cout<<isSet(n);
	return 0;
}
