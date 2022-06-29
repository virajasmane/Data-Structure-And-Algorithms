#include <bits/stdc++.h>
using namespace std;

// 1 plus Floor of Log2 of any number gives the position of set bit(Leftmost).
int isSet(int n)
{
    return (log2(n & ~(n-1))+1);
}

int main()
{
  int n;
  cout<<"Enter a number\n";
  cin>>n;
  cout<<isSet(n);
	return 0;
}
