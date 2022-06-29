#include <bits/stdc++.h>
using namespace std;

bool ispal(string &str, int start, int end)
{
  if(start>=end)
    return true;
  return (str[start]==str[end] && ispal(str, start+1, end-1));
  // Time Complexity :- Theta( n )
  // Auxillary Space :- Theta( n )    where n = str.length()
}

int main()
{
  string str;
  cout<<"Enter the string\n";
  cin>>str;
  cout<<ispal(str, 0, str.length()-1);
	return 0;
}
