#include <bits/stdc++.h>
using namespace std;

//1 <= n <= (10 raiseto 5)
/*Use the logic log(a*b) = log(a) + log(b)
  log(n!) = log(1) + log(2) + ....+ log(n)

  Floor value of log base 10 increased by 1 of any deciaml number gives us no
  of digits present in that decimal number. */

int digitinfact(int n)
{
  double sum = 0.0;
  for(int i=1; i<=n; i++)
    sum += log10(i);
  return (floor(sum)+1);
}

int main()
{
  int x,n;
  cout<<"Enter n \n";
  cin>>n;
  cout<<digitinfact(n);
	return 0;
}
