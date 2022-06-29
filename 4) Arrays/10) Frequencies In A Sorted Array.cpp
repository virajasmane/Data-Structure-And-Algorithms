#include <bits/stdc++.h>
using namespace std;

void frequency(int a[], int n)
{
  int count = 1;
  for(int i=1; i<n; i++)
  {
    if(a[i] == a[i-1])
      count++;
    else
    {
      cout<<a[i-1]<<" : "<<count<<"\n";
      count = 1;
    }
  }
  cout<<a[n-1]<<" : "<<count<<"\n";
  // Time Complexity :- Theta(n)
  // Aux Space :- Theta(1)
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
  frequency(a, n);
  return 0;
}
