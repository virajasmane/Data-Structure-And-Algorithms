// The array is sorted.

#include <bits/stdc++.h>
using namespace std;


int countocc(int a[], int n, int x)
{
  int count = 0;
  for(int i=0; i<n; i++)
    if(a[i] == x)
      count++;
  return count;
  // Time Complexity :- BigO(n)
  // Aux Space :- BigO(1)
}
//______________________________________________________________________________

int firstocc(int a[], int n, int x)
{
  int start = 0, end = n-1, mid;
  while(start <= end)
  {
    mid = (start+end)/2;
    if(a[mid] == x)
    {
      if(a[mid-1] != x || mid == 0)
        return mid;
      else
        end = mid - 1;
    }
    else if(a[mid] > x)
      end = mid - 1;
    else
      start = mid + 1;
  }
  return -1;
}

int lastocc(int a[], int n, int x)
{
  int start = 0, end = n-1, mid;
  while(start <= end)
  {
    mid = (start+end)/2;
    if(a[mid] == x)
    {
      if(a[mid+1] != x || mid == n-1)
        return mid;
      else
        start = mid + 1;
    }
    else if(a[mid] > x)
      end = mid - 1;
    else
      start = mid + 1;
  }
  return -1;
  // Time Complexity :- BigO(n)
  // Aux Space :-BigO(1)
}

int countoccE(int a[], int n, int x)
{
  return firstocc(a, n, x) == -1 ? 0 : lastocc(a, n, x) - firstocc(a, n, x) + 1;
  // Time Complexity :- BigO(Log(n))
  // Aux Space :- BigO(1)
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
  cout<<countoccE(a, n, x);
  return 0;
}
