#include <bits/stdc++.h>
using namespace std;


int getwater(int a[], int n)
{
  int res = 0;
  for(int i=1; i<n-1; i++)
  {
    int lmax = a[i];
    for(int j=0; j<i; j++)
      lmax = max(lmax, a[j]);
    int rmax = a[i];
    for(int j=i+1; j<n; j++)
      rmax = max(rmax, a[j]);
    res = res + min(lmax, rmax) - a[i];
  }
  return res;
  // Time Complexity :- BigO( n^2 )
  // Aux Space :- Theta(1)
}

//______________________________________________________________________________

// Effecient Solution

int getwaterE(int a[], int n)
{
  int res = 0;
  int lmax[n], rmax[n];
  lmax[0] = a[0];
  for(int i=1; i<n; i++)
    lmax[i] = max(a[i], lmax[i-1]);
  rmax[n-1] = a[n-1];
  for(int i=n-2; i>=0; i--)
    rmax[i] = max(a[i], rmax[i+1]);
  for(int i=1; i<n-1; i++)
    res = res + min(lmax[i], rmax[i]) - a[i];
  return res;
  // Time Complexity :- Theta( n )
  // Aux Space :- Theta( n )
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
  cout<<getwaterE(a, n);
  return 0;
}
