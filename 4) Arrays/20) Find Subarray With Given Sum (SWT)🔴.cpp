// Question
// Given an unsorted array of non-negative integers. Find if there is a subarray
// with given sum.
// NOTE: Here non-negative is important beacuse if there are negative
//       nos then the sliding window approach won't work.

// I/P :- arr[] = {1, 4, 20, 3, 10, 5}
//        sum = 33
// O/P :- Yes

#include <bits/stdc++.h>
using namespace std;

bool slidingwindow(int a[], int n, int sum)
{
  int curr_sum = a[0], s = 0;  // s is starting index, e is ending index
  for(int e=1; e<n; e++)
  {
    //First clear the window if curr_sum > sum
    //The order of while and if loops should be preserved, they are imp here.
    while(curr_sum > sum && s < e-1)
    {
      curr_sum -= a[s];
      s++;
    }
    if(curr_sum == sum)
      return true;
    curr_sum += a[e];
  }
  return false;
}

int main()
{
  int n,k;
  cout<<"Enter N and sum\n";
  cin>>n>>sum;
  int a[n];
  cout<<"Enter the elements of array\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<slidingwindow(a, n, sum);
  return 0;
}
