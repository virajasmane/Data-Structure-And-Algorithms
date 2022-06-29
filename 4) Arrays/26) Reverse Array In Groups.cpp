// Eg
// Input:
// N = 5, K = 3
// arr[] = {1,2,3,4,5}
// Output: 3 2 1 5 4
// Explanation: First group consists of elements
// 1, 2, 3. Second group consists of 4,5.

#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n)
{
  for(int i=0; i<n; i+=k)
  {
      int left = i;
      int right = min(i+k-1, n-1);
      while(left < right)
        swap(arr[left++], arr[right--]);
  }
  // Time Complexity :- BigO(n)
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
  reverse(a, n);
  for(int i=0; i<n; i++)
    cout<<a[i]<<" ";
  return 0;
}
