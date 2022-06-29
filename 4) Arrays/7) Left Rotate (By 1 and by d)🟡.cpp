#include <bits/stdc++.h>
using namespace std;

void leftrotate(int a[], int n) // Left Rotate By 1.
{
  int temp=a[0];
  for(int i=0; i<n-1; i++)
    a[i] = a[i+1];
  a[n-1] = temp;
  // Time Complexity :- Theta(n)
  // Aux Space :- Theta(1)
}

//______________________________________________________________________________

void leftrotate(int a[], int n, int d) // Left Rotate By d.
{                                      // Naive solution

  for(int j=0; j<d; j++)
  {
    leftrotate(a, n);
  }
  // Time Complexity :- Theta(n*d)
  // Aux Space :- Theta(1)
}

//______________________________________________________________________________

void leftrotateE(int a[], int n, int d)  // Takes Theta(d) extra space.
{
  int arr[d];
  for(int i=0; i<d; i++)
    arr[i] = a[i];
  for(int i=0; i<n-d; i++)
    a[i] = a[i+d];
  for(int i=0; i<d; i++)
    a[n-d+i] = arr[i];
  // Times Complexity :- Theta(n)
  // Aux Space :- Theta(d)
}

//______________________________________________________________________________

void reverse(int a[], int x, int y)
{
  while(x<=y)
  {
    swap(a[x],a[y]);
    x++;
    y--;
  }
}

void leftrotateO(int a[], int n, int d) // Takes Theta(1) extra space
{
  reverse(a, 0, d-1);
  reverse(a, d, n-1);
  reverse(a, 0, n-1);
  // Time Complexity :- Theta(n)
  // Aux Space :- Theta(1)
}



int main()
{
  int n,d;
  cout<<"Enter N \n";
  cin>>n>>d;
  int a[n];
  cout<<"Enter the elements of array\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  leftrotateO(a, n, d);
  for(int i=0; i<n; i++)
    cout<<a[i]<<" ";
  return 0;
}
