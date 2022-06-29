// Given an array arr[] of size N where every element is in the range from 0 to n-1.
// Rearrange the given array so that arr[i] becomes arr[arr[i]].

// Eg
// Input:
// N = 5
// arr[] = {4,0,2,1,3}
// Output: 3 4 2 0 1

// Explanation:
// arr[arr[0]] = arr[4] = 3.
// arr[arr[1]] = arr[0] = 4.
// and so on.

// Constraints:
// 1 <= N <= 107
// 0 <= Arr[i] < N

#include<bits/stdc++.h>
using namespace std;

void arrange(int a[], int n)
{
  int maxx = n;
  for(int i =0; i<n; i++)
    a[i] = a[i] + a[a[i]] % maxx * maxx;
  for(int i=0; i<n; i++)
    a[i] /= n;
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
  arrange(a, n);
  for(int i=0; i<n; i++)\
    cout<<a[i]<<" ";
  return 0;
}
