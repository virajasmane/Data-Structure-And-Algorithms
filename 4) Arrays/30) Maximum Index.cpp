// Given an array A[] of N positive integers. The task is to find the maximum of
// j - i subjected to the constraint of A[i] <= A[j].

// Input:
// N = 9
// A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
// Output:
// 6

// Explanation:
// In the given array A[1] < A[7]
// satisfying the required
// condition(A[i] <= A[j]) thus giving
// the maximum difference of j - i
// which is 6(7-1).

// Solution Explained:
// Lets consider any example [7 3 1 8 9 10 4 5 6]
// what is maxRight ?
// Filling from right side 6 is first element now 6 > 5 so again we fill 6 till we
// reach 10 > 6 :
// [10 10 10 10 10 10 6 6 6] this is maxR
// [7 3 1 1 1 1 1 1 1 ] this is minL
// now we see that how to reach answer from these to and its proof !!!
// lets compare first elements of the arrays now we see 10 > 7,
// now we increase maxR by 1 till it becomes lesser than 7 i.e at index 5
// hence answer till now is. 5-0 = 5
// now we will increase minL we get 3 which is lesser than 6 so we increase maxR
// till it reaches last index and the answer becomes 8-1= 7
// so we see how we are getting correct answer.
// As we need the max difference j – i such that A[i]<= A[j], hence we do not need
// to consider element after the index j and element before index i.
// in previous hint, make 2 arrays,
// First, will store smallest occurring element before the element
// Second, will store largest occurring element after the element
// Traverse the Second array, till the element in second array is larger than or
// equal to First array, and store the index difference. And if it becomes smaller,
// traverse the first array till it again becomes larger.
// And store the max difference of this index difference.

#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(int arr[], int n)
{
  int LMIN[n], RMAX[n];
  LMIN[0] = arr[0];
  for(int i=1; i<n; i++)
    LMIN[i] = min(arr[i], LMIN[i-1]);
  RMAX[n-1] = arr[n-1];
  for(int i=n-2; i>=0; i--)
    RMAX[i] = max(arr[i], RMAX[i+1]);
  int i = 0, j = 0, max_diff = -1;
  while(i<n && j<n)
  {
    if(LMIN[i] <= RMAX[j])
    {
      max_diff = max(max_diff, j-i);
      j += 1;
    }
    else
      i +=1;
  }
  return max_diff;
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
  cout<<maxIndexDiff(a, n);
  return 0;
}
