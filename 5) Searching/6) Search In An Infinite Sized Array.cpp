// The array is sorted.
// Find the number in an infinite array.

#include <bits/stdc++.h>
using namespace std;


int search(int a[], int x) // Naive solution
{
  int i = 0;
  while(1)
  {
    if(a[i] == x)
      return i;
    if(a[i] > x)
      return -1;
    i++;
  }
  // Time Complexity :- BigO( position of the element)
  // Aux Space :- BigO(1)
}
//______________________________________________________________________________

// Unbounded Binary search

int bsearch(int a[], int x, int start, int end)
{
  while(start <= end)
  {
      int mid = (start+end)/2;
      if(a[mid] == x)
        return mid;
      else if(a[mid] < x)
        start = mid + 1;
      else
        end = mid - 1;
  }
  return -1;
}

int searchE(int a[], int x)
{
  if(a[0] == x)
    return 0;
  int i = 1;
  while(a[i] < x)
    i *= 2;
  if(a[i] == x)
    return i;
  return bsearch(a, x, (i/2)+1, i-1);
  // Time Complexity :- BigO( Log(n) )
  // Aux Space :- BigO(1)
}


int main()
{
  int n, x;
  cout<<"Enter no of elements \n";
  cin>>n;
  cout<<"Enter the element to be found\n";
  cin>>x;
  int a[n];
  cout<<"Enter the elements\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<searchE(a, x);
  return 0;
}
