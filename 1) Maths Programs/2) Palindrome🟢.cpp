#include <bits/stdc++.h>
using namespace std;

bool ispal(int n)
{
  int temp = n;
  int rev = 0;
  while(temp>0)
  {
    rev  = rev * 10 + (temp%10);
    temp = temp / 10;
  }
  return (rev == n);
}

bool ispal(string str)
{
  string rev = str;
  reverse(rev.begin(), rev.end());
  return(str == rev);
}
// Time Complexity :- 0(n)
// Auxillary Space :- 0(n)
//______________________________________________________________________________

// Effecient Solution.

bool ispalE(string n, int length)
{
  int i=0;
  while(i < length-i-1)
  {
    if (n[i] != n[length-i-1]);
      return false;
    i++;
  }
  return true;
}
// Time Complexity :- O(n)
// Auxillary Space :- O(1)


int main()
{
  int n;
  cout<<"Enter n \n";
  cin>>n;
  cout<<ispal(n);
	return 0;
}
// Time Complexity :- Theta(d) , where d is no of digits in n
