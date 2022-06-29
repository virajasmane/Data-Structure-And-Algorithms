// The array is sorted and rotated.


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
  // Time Complexity :- BigO(position of x)
  // Aux Space :- BigO(1)
}
//______________________________________________________________________________

//this code is written by me. not so optimised by the next one
int bsearch(int a[], int n, int x, int start, int end)
{
  int mid = (start+end)/2;
  while(start <= end)
  {
    if(a[mid] == x)
      return mid;
    else if(a[mid] >= x)
      end = mid - 1;
    else
      start = mid + 1;
  }
  return -1;
}


int searchE(int a[], int n, int x, int start, int end)
{
  int mid = (start+end)/2;

  if(a[mid] == x) // check the first element explicitly.
    return mid;

  if(start > end) // recursion base case
    return -1;

  if(a[start] < a[mid]) // Left half is sorted
  {
    if(x >= a[start] && x < a[mid]) // if x is present in left half we'll get it's value
      return bsearch(a, n, x, start, mid-1);
    else // if not present in left half then might be present in right half, so recursively call the function for right half since it is not sorted.
      return searchE(a, n, x, mid+1, end);
  }
  else // Right half is sorted
  {
    if(x > a[mid] && x <= end)
      return bsearch(a, n, x, mid+1, end);
    else
      return searchE(a, n, x, start, mid-1);
  }

  // Time Complexity :- BigO(Log(n))
  // Aux Space :-
}
//______________________________________________________________________________

//this is the optimised code, logic is same in both this and above function

int searchE(int a[], int n, int x)
{
  int start = 0, end = n-1;
  int mis = (start+end)/2;
  while(start <= end)
  {
    if(a[mid] == x)
      return mid;
    else if(a[mid > x])
      end = mid - 1;
    else
      start = mid + 1; // Till here is the bsearch.

    if(a[start] < a[mid]) // Left half is sorted
    {
      if(x >= a[start] && x < a[mid])
        end = mid - 1;
      else
        start = mid + 1;
    }
    else // Right half is sorted
    {
      if(x > a[mid] && x <= end)
        start = mid + 1;
      else
        end = mid - 1;
    }
  }
  return -1;
  // Time Complexity :- BigO(Log(n))
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
  cout<<searchE(a, n, x, 0, n-1);
  return 0;
}
