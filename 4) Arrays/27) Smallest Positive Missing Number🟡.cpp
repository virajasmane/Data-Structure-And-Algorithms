// Question

// Eg 1
// Input:
// N = 5
// arr[] = {1,2,3,4,5}
// Output: 6
// Explanation: Smallest positive missing
// number is 6.

// Eg 2
// Input:
// N = 5
// arr[] = {0,-10,1,3,-20}
// Output: 2
// Explanation: Smallest positive missing
// number is 2.

#include <bits/stdc++.h>
using namespace std;

int missingNumber(int a[], int n)
{
  for(int i=0; i<n; i++)
  {
    int correctpos = a[i]-1;
    if(a[i] > 0 && a[i] <n)
      while(a[i] > 0 && a[i] <= n && a[i] != a[correctpos])
      {
        swap(a[i], a[correctpos]);
        correctpos = a[i]-1;
      }
  }
  for(int i=0; i<n; i++)
  if(a[i] != i+1)
    return i+1;
  return n+1;
        // Time Complexity :- BigO(n)
        // Aux Complexity :- Theta(1)
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
  cout<<missingno(a, n);
  return 0;
}
