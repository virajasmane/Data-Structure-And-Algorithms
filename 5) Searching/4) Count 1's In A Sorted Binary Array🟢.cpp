// The array is sorted.

#include <bits/stdc++.h>
using namespace std;


int countones(int a[], int n)
{
  int count = 0;
  for(int i=0; i<n; i++)
    if(a[i] == 1)
      count++;
  return count;
  // Time Complexity :- BigO(n)
  // Aux Space :- BigO(1)
}
//______________________________________________________________________________

int countonesE(int a[], int n)
{
  int start = 0, end = n-1, mid;
  while(start <= end)
  {
    mid = (start+end)/2;
    if(a[mid] == 1)
    {
      if(a[mid-1] == 0 || mid == 0)
        return (n-mid);
      else
        end = mid - 1;
    }
    else
      start = mid + 1;
  }
  return 0;
  // Time Complexity :-
  // Aux Space :-
}


int main()
{
  int n, x;
  cout<<"Enter N \n";
  cin>>n;
  int a[n];
  cout<<"Enter the elements of array\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<countonesE(a, n);
  return 0;
}
