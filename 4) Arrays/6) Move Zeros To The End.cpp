#include <bits/stdc++.h>
using namespace std;

void movezeros(int a[], int n) //Naive Method
{
  for(int i=0; i<n; i++)
  {
    if(a[i] == 0)
    {
      for(int j=i+1; j<n; j++)
        if(a[j] != 0)
        {
          swap(a[i],a[j]);
          break;
        }
    }
  }
  // Time Complexity :- BigO(  square(n) )
}
//______________________________________________________________________________

// Now a solution which has Time Complexity BigO(n)

void movezerosE(int a[], int n)
{
  int count = 0;
  for(int i=0; i<n; i++)
  {
    if(a[i] != 0)
    {
      swap(a[count], a[i]);
      count++;
    }
  }
}


int main()
{
  int n;
  cout<<"Enter N \n";
  cin>>n;
  int a[n];
  cout<<"Enter the elements of array\n";
  for(int i=0;i<n;i++)
    cin>>a[i];
  movezerosE(a, n);
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  return 0;
}
