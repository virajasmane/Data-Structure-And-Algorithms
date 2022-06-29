// Input :- 7
         // 2 3 10 6 4 8 1
// Output :- 8
// We've to get maximum a[j]-a[i], where j>i 

#include <bits/stdc++.h>
using namespace std;


int maxdifference(int a[], int n) // Naive Solution
{
  int res = a[1] - a[0];
  for(int i=0; i<n-1; i++)
    for(int j=i+1; j<n; j++)
      res = max(res, a[j]-a[i]);
  return res;
  // Time Complexity :- Theta(square(n))
  // Aux Space :- Theta(1)
}
//______________________________________________________________________________

int maxdifferenceE(int a[], int n) // Effecient Solution
{
  int res = a[1]-a[0], minval = a[0];
  for(int j=1; j<n; j++)
  {
    res = max(res, a[j]-minval);
    minval = min(minval, a[j]);
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
  int a[n];
  cout<<"Enter the elements of array\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<maxdifferenceE(a, n);
  return 0;
}
