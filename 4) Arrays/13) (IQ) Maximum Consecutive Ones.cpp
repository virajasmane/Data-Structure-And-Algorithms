// Warm up or Follow up problem that might be asked in an interview.

#include <bits/stdc++.h>
using namespace std;


int maxones(bool a[], int n)
{
  int currmax = 0, res = 0;
  for(int i=0; i<n; i++)
  {
    if(a[i] == 0)
      currmax = 0;
    else
    {
      currmax++;
      res = max(res, currmax);
    }
  }
  return res;
  // Time Complexity :- Theta(n)
  // Aux Space :- Theta(1)
}



int main()
{
  int n;
  cout<<"Enter N \n";
  cin>>n;
  bool a[n];
  cout<<"Enter the elements of array\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<maxones(a, n);
  return 0;
}
