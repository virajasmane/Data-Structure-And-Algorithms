#include <bits/stdc++.h>
using namespace std;

int ropecut(int n, int a, int b, int c)
{
  if(n==0)
    return 0;
  if(n<0)
    return -1;
  int res = max({ ropecut(n-a,a,b,c), ropecut(n-b,a,b,c), ropecut(n-c,a,b,c) });
  if(res==-1)
    return -1;
  return (res+1);
  // Time Complexity :- BigO( 3 raiseto n )  put a,b,c = 1 and check to understand it
}

int main()
{
  int n,a,b,c;
  cout<<"Enter the value of n, a, b and c\n";
  cin>>n>>a>>b>>c;
  cout<<ropecut(n,a,b,c);
	return 0;
}
