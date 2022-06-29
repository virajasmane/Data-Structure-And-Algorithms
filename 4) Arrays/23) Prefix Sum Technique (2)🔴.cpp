// Question
// Given an array of int find if it has a equilibrium point.
// Eg I/p :- arr = {3, 4, 8, -9, 20, 6}
//    O/P :- Yes

#include <bits/stdc++.h>
using namespace std;

void iseqpt(int a[], int n) // Naive Solution
{
  for(int i=0; i<n; i++)
  {
    int lsum = 0, rsum = 0;
    for(int j=0; j<i; j++)
      lsum += a[j];
    for(int k=i+1; k<n; k++)
      rsum += a[k];
    if(lsum == rsum)
    {
      cout<<"YES";
      return;
    }
  }
  cout<<"NO";
  // Time Complexity :- BigO(n^2)
  // Aux Complexity :- Theta(1)
}

//______________________________________________________________________________
//Effecient solution using prefix sum technique.

// Now one way is to calculate prefix sum and suffix sum and if any index has
// same prefix and suffix sum then that is the equilibrium pt but that will require
// BigO(n) time and Big(n) extra space we want to think of a solution which will
// work in BigO(n) time and Theta(1) extra space.

// In the below solution we first calculate sum (ie sum of all elements in array)
// and then go on from left to right in array and maintain a left_sum var and
// check if left_sum is equal to sum-current element.

void iseqptE(int a[], int n)
{
  int sum = 0;
  for(int i=0; i<n; i++)
    sum += a[i];
  int l_sum = 0;
  for(int i=0; i<n; i++)
  {
    if(l_sum == sum-a[i])
    {
      cout<<"YES";
      return;
    }
    l_sum += a[i];
    sum -= a[i];
  }
  cout<<"NO";
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
  iseqptE(a, n);
  return 0;
}
