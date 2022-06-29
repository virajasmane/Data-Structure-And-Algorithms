// A element in an array is a leader if all the elements on the right of it
// are smaller than that number (not even equal, smaller !!)
// Eg
// Input  :- 7 10 4 3 6 5 2
// Output :- 10 6 5 2

#include <bits/stdc++.h>
using namespace std;


void leader(int a[], int n)
{
  for(int i=0; i<n; i++)
  {
    bool flag = false;
    for(int j=i+1; j<n; j++)
    {
      if(a[i] <= a[j])
      {
        flag = true;
        break;
      }
    }
    if(flag == false)
      cout<<a[i]<<" ";
  }
  // Time Complexity :- Theta(n^2)
  // Aux Space :- Theta(1)
}

//______________________________________________________________________________

void leaderE(int a[], int n)
{
  int curr_leader = a[n-1];
  cout<<a[n-1]<<" ";
  for(int i=n-2; i>=0; i--)
  {
    if(curr_leader < a[i])
    {
      curr_leader = a[i];
      cout<<a[i]<<" ";
    }
  }
  // Time Complexity :- Theta(n)
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
  leaderE(a, n);
  return 0;
}
