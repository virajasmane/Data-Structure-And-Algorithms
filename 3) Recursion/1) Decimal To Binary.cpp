#include <bits/stdc++.h>
using namespace std;

int DtoB(int n)
{
  if(n==0)
    return 0;
  DtoB(n/2);
  cout<<(n%2);
}

int main()
{
  int n;
  cout<<"Enter the value of n.\n";
  cin>>n;
  DtoB(n);
	return 0;
}
