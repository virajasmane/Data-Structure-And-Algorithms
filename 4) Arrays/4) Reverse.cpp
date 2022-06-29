#include <bits/stdc++.h>
using namespace std;


void reverse(int a[], int N)
{
  for(int i=0; i<=N/2; i++)
  {
    swap(a[i],a[N-i-1]);
  }
  // Time Complexity :- Theta( N )
  // Aux Space :- Theta( 1 )
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
  reverse(a, N);
  for(int i=0;i<N;i++)
    cout<<a[i]<<" ";
  return 0;
}
