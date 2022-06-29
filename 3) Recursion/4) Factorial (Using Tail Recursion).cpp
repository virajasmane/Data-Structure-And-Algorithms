#include <bits/stdc++.h>
using namespace std;

int fact(int n) // Non Tail-Recursive Function
{
  if(n<1)
    return 1;
  return n * fact(n-1);
}


int fact(int n, int k) // Tail-Recursive Function
{
  if(n==0 || n==1)
    return k;
  fact(n-1,k*n);
}

int main()
{
  int n,k=1;
  cout<<"Enter the value of n.\n";
  cin>>n;
  cout<<fact(n,k);
	return 0;
}
