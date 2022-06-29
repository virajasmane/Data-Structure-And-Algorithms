#include <bits/stdc++.h>
using namespace std;

int multiplicationUnderModulo(long long a,long long b)
{
    int m = 1000000007;
    return ((a%m)*(b%m))%m;
}

int main()
{
  long long int a,b;
  cout<<"Enter a and b \n";
  cin>>a>>b;
  cout<<multiplicationUnderModulo1(a,b);
	return 0;
}
