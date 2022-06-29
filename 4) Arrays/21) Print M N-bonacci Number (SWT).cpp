// Question
// In N-bonacci sequence, we use sum of preceding N numbers from the next term.
// For example, a 3-bonacci sequence is the following:
// 0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81

#include <bits/stdc++.h>
using namespace std;

void slidingwindow(int n, int m) // Naive Solution
{
  int a[m] = {0};
  a[n-1] = 1;

  for(int i=n; i<m; i++)
    for(int j=i-n; j<i; j++)
      a[i] += a[j];

  for(int i=0; i<m; i++)
    cout<<a[i]<<" ";
  // Time Complexity :- BigO(m*n)
  // Space Complexity :- BigO(m)
}
//______________________________________________________________________________

// Effecient Solution Based on Slding Window Technique.

void slidingwindowE(int n, int m)
{
  int a[m] = {0};
  a[n-1] = 1;
  a[n] = 1;
  for(int i=n+1; i<m; i++)
    a[i] = 2 * a[i-1] - a[i-n-1];
  for(int i=0; i<m; i++)
    cout<<a[i]<<" ";
  // Time Complexity :- BigO(m)
  // Aux Space :- BigO(m)
}

int main()
{
  int n,m;
  cout<<"Enter N and m\n";
  cin>>n>>m;
  slidingwindowE(n, m);
  return 0;
}
