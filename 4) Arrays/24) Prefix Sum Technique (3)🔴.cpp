// Question
// Given n ranges find the maximum appearing element in the range.
// Eg I/P :- L[] = {1, 2, 3}
//           R[] = {3, 5, 7}
//    O/P :- 3
// Explaination :- the ranges are {l[0] to R[0]}, {l[1] to R[1]}, {l[2] to R[2]}
//                           ie   {1 to 3}, {2 to 5}, {3 to 7}
//                           ie   {1, 2, 3}, {2, 3, 4, 5}, {3, 4, 5, 6, 7}
// So the number appearing max no of times is 3 so the O/P is 3.

#include <bits/stdc++.h>
using namespace std;

int maxrange(int L[], int R[], int n)
{
  int arr[1000] = {0};
  for(int i=0; i<n; i++)
  {
    arr[ L[i] ]++;
    arr[ R[i] + 1 ]--;
  }
  int maxe = arr[0], res = 0;
  for(int i=1; i<1000; i++)
  {
    arr[i] += arr[i-1];
    if(maxe < arr[i])
    {
      maxe = arr[i];
      res = i;
    }
  }
  return res;
  // Time Complexity :- BigO(n)
  // Aux Complexity :- BigO(1000)
}


int main()
{
  int n;
  cout<<"Enter N \n";
  cin>>n;
  int L[n], R[n];
  cout<<"Enter the elements of 1st array\n";
  for(int i=0; i<n; i++)
    cin>>L[i];
  cout<<"Enter the elements of 2st array\n";
  for(int i=0; i<n; i++)
    cin>>R[i];
  cout<<maxrange(L, R, n);
  return 0;
}
