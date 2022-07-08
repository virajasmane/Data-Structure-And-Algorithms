/* Given a string s print all its Permutation and combinations
   eg s = "abc"
   O/P :- " " "a" "b" "c" "ab" "bc" "ac" "abc" */

#include <bits/stdc++.h>
using namespace std;

void powerSet(string s)
{
  int n = s.length();
  int powSize = pow(2,n);
  for(int counter=0; counter<powSize; counter++)
  {
    for(int j=0; j<n; j++)
    {
      if((counter & (1<<j)) != 0)
        cout<<s[j];
    }
    cout<<"\n";
  }
  // Time Complxity :- Theta( 2^n * n )
}

int main()
{
  string s;
  cout<<"Enter a String\n";
  cin>>s;
  powerSet(s);
	return 0;
}
