// Given an array of integers and a number k, find the maximum sum of k
// consecutive elements.
// arr[] = {1, 8, 30, -5, 20, 7}
// k = 3
// so 1 + 8 + 30 = 39
   // 8 + 30 + (-5) = 33
   // 30 + (-5) + 20 = 45
   // (-5) + 20 + 7 = 22
// Max is 45 so return 45


#include <bits/stdc++.h>
using namespace std;


int slidingwindow(int a[], int n, int k)  // Naive Solution
{
  int res = INT_MIN;
  for(int i=0; i+k-1<n; i++)
  {
    int sum = 0;
    for(int j=0; j<k; j++)
      sum += a[i+j];
    res = max(res, sum);
  }
  return res;
  // Time Complexity :- BigO((n-k)*k) ie BigO(n^2)
  // Aux Space :- Theta(1)
}
//______________________________________________________________________________



int slidingwindowE(int a[], int n, int k) // Effecient Solution
{
  int curr_sum = 0;
  for(int i=0; i<k; i++)
    curr_sum += a[i];
  int max_sum = curr_sum;
  for(int i=k; i<n; i++)
  {
    curr_sum += (a[i] - a[i-k]);
    max_sum = max(max_sum, curr_sum);
  }
  return max_sum;
  // Time Complexity :- BigO(k) + Big(n-k) ie BigO(n)
  // Aux Space :- Theta(1)
}



int main()
{
  int n,k;
  cout<<"Enter N and k\n";
  cin>>n>>k;
  int a[n];
  cout<<"Enter the elements of array\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<slidingwindowE(a, n, k);
  return 0;
}
