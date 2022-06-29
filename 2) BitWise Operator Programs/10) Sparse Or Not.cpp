#include <bits/stdc++.h>
using namespace std;

bool isSparse(int n)
{
    return ((n & (n>>1)) == 0);
}

int main()
{
  int n;
  cout<<"Enter a number\n";
  cin>>n;
  cout<<isSparse(n);
	return 0;
}
