
#include <bits/stdc++.h>
using namespace std;


int bsearch(int a[], int n, int x) //Iterative
{
  int start = 0, end = n-1, mid;
  while(start <= end)
  {
    mid = (start+end)/2;
    if(a[mid] == x)
      return mid;
    else if(a[mid] > x)
      end = mid-1;
    else
      start = mid+1;
  }
  return -1;
  // Time Complexity :- BigO(n)
  // Aux Space :- BigO(1)
}
//______________________________________________________________________________

int bsearch(int a[], int n, int x, int start, int end) // Recursive
{
  if(start > end)
    return -1;
  int mid = (start+end)/2;
  if(a[mid] == x)
    return mid;
  else if(a[mid] > x)
    return bsearch(a, n, x, start, mid-1);
  else
    return bsearch(a, n, x, mid+1, end);
  // Time Complexity :- BigO(n)
  // Aux Space :- BigO( Log(n) )
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
  cout<<"Enter the element to be found in the array\n";
  cin>>x;
  cout<<bsearch(a, n, x);
  return 0;
}
