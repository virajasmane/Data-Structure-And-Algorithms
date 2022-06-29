#include <bits/stdc++.h>
using namespace std;

int countdigit(int n)
{
  int count = 0;
  while(n>0)
  {
    n/=10;
    count++;
  }
  return count;
  // TIME COMPLEXITY :-  Theta(log(n))
}

int main()
{
  int n;
  cout<<"Enter n \n";
  cin>>n;
  int x = countdigit(n);
  cout<<x;
	return 0;
}
