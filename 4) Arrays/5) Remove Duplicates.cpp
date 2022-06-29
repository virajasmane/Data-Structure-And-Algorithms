#include <bits/stdc++.h>
using namespace std;

int removeduplicate(int a[], int n) //Naive Method
{
  int temp[n],size=1;
  temp[0] = a[0];
  for(int i=1; i<n; i++)
  {
    if(temp[size-1] != a[i])
    {
      temp[size] = a[i];
      size++;
    }
  }
  for(int i=0; i<size; i++)
  {
    a[i] = temp[i];
  }
  return size;
  // Time Complexity :- BigO( n )
  // Aux Space :- BigO( n )
}
//______________________________________________________________________________

// Now a solution with takes same Time Complexity but BigO(1) Aux Space.

int removeduplicateE(int a[], int n)
{
  int size=1;
  for(int i=1; i<n; i++)
    if(a[size-1] != a[i])
    {
      a[size] = a[i];
      size++;
    }
  return size;
  // Time Complexity :- BigO( n )
  // Aux Space :- BigO( 1 )
}

int main()
{
  int N;
  cout<<"Enter N \n";
  cin>>N;
  int a[N];
  cout<<"Enter the elements of array\n";
  for(int i=0;i<N;i++)
    cin>>a[i];
  cout<<removeduplicateE(a, N);
  return 0;
}
