// What is a Sub array?
// Sub arrays of {1, 2, 3} are
// {1}, {2}, {3}, {1, 2}, {2, 3}, {1, 2, 3}
// Note :- {1,3} is not a subarray because 1 and 3 are not concecutive.

#include <bits/stdc++.h>
using namespace std;


int maxsubarray(int a[], int n)
{
  int res=0;
  for(int i=0; i<n; i++)
  {
    int currsum=0;
    for(int j=i; j<n; j++)
    {
      currsum += a[j];
      res = max(res, currsum);
    }
  }
  return res;
  // Time Complexity :- Theta(n^2)
  // Aux Space :- Theta(1)
}
//______________________________________________________________________________

// Kadane's Algorithm

int maxsubarrayE(int a[], int n)
{
  int res = a[0], finalres = a[0];
  for(int i=1; i<n; i++)
  {
    res = max(res+a[i], a[i]);
    finalres = max(finalres, res);
  }
  return finalres;
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
  cout<<maxsubarrayE(a, n);
  return 0;
}
