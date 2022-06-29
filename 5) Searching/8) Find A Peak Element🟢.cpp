// Peak element is not smaller than it's neighbours (immidiate left and right).
// for the 1st element only check right side and for the last element check left side
// there is always a peak element in an independent array.

#include <bits/stdc++.h>
using namespace std;


int findpeak(int a[], int n) // Naive solution
{
  if(n==1 || a[0] > a[1])
    return a[0];
  if(a[n-1] > a[n-2])
    return a[n-1];

  for(int i=1; i<n-1; i++)
    if(a[i] >= a[i-1] && a[i] >= a[i+1])
      return a[i];
  // Time Complexity :- BigO(n)
  // Aux Space :- BigO(1)
}
//______________________________________________________________________________

int findpeakE(int a[], int n)
{
  int start = 0, end = n-1;
  while(start <= end)
  {
    int mid = (start+end)/2;
    if( (mid==0 || a[mid] >= a[mid-1]) && (mid=n-1 || a[mid] > a[mid+1]) )
      return a[mid];
    else if(mid>0 && a[mid] < a[mid-1])
      end = mid - 1;
    else
      start = mid + 1;
  }
  return -1; // will never come here, there will alwasy be a peak
  // Time COmplexity :- BigO(Log(n))
   // Aux Space :- BigO(1)
}

int main()
{
  int n;
  cout<<"Enter no of elements \n";
  cin>>n;
  int a[n];
  cout<<"Enter the elements\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<findpeakE(a, n);
  return 0;
}
