#include <bits/stdc++.h>
using namespace std;

long long sumUnderModulo(long long a, long long b)
{
  const unsigned int M=1000000007;
  return (a%M+b%M)%M;
}

int main()
{
  long long int a,b;
  cout<<"Enter a and b \n";
  cin>>a>>b;
  cout<<sumUnderModulo(a,b);
	return 0;
}
