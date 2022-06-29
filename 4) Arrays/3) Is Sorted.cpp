#include <bits/stdc++.h>
using namespace std;


bool issorted(int a[], int N)
{
  for(int i=0; i<N-1; i++)
  {
    if(a[i]>a[i+1])
      return false;
  }
  return true;
  // Time Complexity :- BigO( N )
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
  cout<<issorted(a, N);
  return 0;
}
