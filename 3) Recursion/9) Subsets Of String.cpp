#include <bits/stdc++.h>
using namespace std;

void subset(string str, string curr, int index)
{
  if(index == str.length())
  {
    cout<<curr<<"\t";
    return;
  }
  subset(str, curr, index+1);
  subset(str, curr+str[index], index+1);
  // Time Complexity :- Theta( pow(2,n) ) where n is length of string
  // Space Complexity :- BigO( n ) where n is length of string
}

int main()
{
  string str;
  cout<<"Enter the string\n";
  cin>>str;
  subset(str, "", 0);
	return 0;
}
