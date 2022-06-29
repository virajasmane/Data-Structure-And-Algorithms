// What is a Sub array?
// Sub arrays of {1, 2, 3} are
// {1}, {2}, {3}, {1, 2}, {2, 3}, {1, 2, 3}
// Note :- {1,3} is not a subarray because 1 and 3 are not concecutive.

#include <bits/stdc++.h>
using namespace std;


int maxevenodd(int a[], int n)
{
  int res = 1;
  for(int i=0; i<n; i++)
  {
    int curr = 1;
    for(int j=i+1; j<n; j++)
    {
      if((a[j]%2==0 && a[j-1]%2!=0) || (a[j]%2!=0 && a[j-1]%2==0))
        curr++;
      else
        break;
    }
    res = max(res, curr);
  }
  return res;
  // Time Complexity :- BigO(n^2)
  // Aux Space :- Theta(1)
}
//______________________________________________________________________________

// Kadane's Algorithm

int maxevenoddE(int a[], int n)
{
  int res = 1, curr = 1;
  for(int i=1; i<n; i++)
  {
    if((a[i]%2==0 && a[i-1]%2!=0) || (a[i]%2!=0 && a[i-1]%2==0))
    {
      curr++;
      res = max(res, curr);
    }
    else
      curr = 1;
  }
  return res;
  // Time Complexity :- BigO(n)
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
  cout<<maxevenoddE(a, n);
  return 0;
}
