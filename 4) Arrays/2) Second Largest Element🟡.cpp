#include <bits/stdc++.h>
using namespace std;

int largestelement(int a[], int N)
{
  int i,largest = 0;
  for(i=1; i<N; i++)
    if(a[i] > a[largest])
      largest = i;
  return largest;
  // Time Complexity :- Theta( n )
}

int secondlargestelement(int a[], int N)
{
  int largest = largestelement(a, N);
  int i,res = -1;
  for(i=0; i<N; i++)
  {
    if(a[i] != a[largest])
    {
      if(res == -1)
        res = i;
      else if(a[i] > a[res])
        res = i;
    }
  }
  return a[res];
}
//______________________________________________________________________________

// Earlier we did two traversal now find the second largest by doing only one
// traversal.

int secondlargestelementE(int a[], int N)
{
  int largest = 0, res = -1;
  for(int i=1; i<N; i++)
  {
    if(a[i] > a[largest])
      {
        res = largest;
        largest = i;
      }
    else if(a[i] < a[largest])
    {
      if(res==-1)
        res = i;
      else if(a[i] > a[res])
        res = i;
    }
  }
  return a[res];
  // Time Complexity :- Theta( n )
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
  cout<<"Second Largest Element is "<<secondlargestelementE(a, N);
  return 0;
}
