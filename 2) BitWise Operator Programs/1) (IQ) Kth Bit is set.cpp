// MICROSOFT QUESTION !!!!

// Given a number n, find out if the kth bit is set or not.

#include <bits/stdc++.h>
using namespace std;

void isSetL(int n, int k)// Using Left Shift Operator
{
  if(n&(1<<(k-1)) != 0)
    cout<<"Yes";
  else
    cout<<"No";
}

void isSetR(int n, int k)// Using Right Shift Operator
{
  if(( (n>>(k-1)) & 1) == 1)
    cout<<"Yes";
  else
    cout<<"No";
}

int main()
{
  int n,k;
  cout<<"Enter n and k \n";
  cin>>n>>k;
  isSetR(n,k);
	return 0;
}
