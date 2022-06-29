#include<bits/stdc++.h>
using namespace std;


void intersection(vector<int> &a, vector<int> &b, int n, int m) //Naive Solution
{
  for(int i=0; i<n; i++)
  {
    if(i>0 && a[i]==a[i-1])
      continue;
    for(int j=0; j<m; j++)
    {
      if(a[i]==b[j])
      {
        cout<<a[i]<<" ";
        break;
      }
    }
  }
}
// Time Complexity :- O(n * m)
// Aux Space :- O(1)

//______________________________________________________________________________
// Effecient Solution
// Use merge sort technique.

void intersectionE(a, b, n, m)
{
  int i=0, j=0;
  while(i<n && j<m)
  {
    if(i>0 && a[i]==a[i-1])
    {
      i++;
      continue;
    }
    if(a[i] < b[j])
      i++;
    else if(b[j] < a[i])
      j++;
    else
    {
      cout<<a[i]<<" ";
      i++;
      j++;
    }
  }
  // Time Complexity :- O(max(n,m));
  // Aux Space :- O(1)
}


int main()
{
  int n;
  cout<<"Enter the no of elements of 1st array\n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements of 1st array \n";
  for(auto &i: a)
    cin>>i;
  int m;
  cout<<"Enter the no of elements of 2st array\n";
  cin>>m;
  vector<int> b(m);
  cout<<"Enter the elements of 2st array \n";
  for(auto &i: b)
    cin>>i;
  intersection(a, b, n, m);
  return 0;
}
