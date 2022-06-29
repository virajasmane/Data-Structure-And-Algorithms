// Question
// Given an array arr[] of N distinct integers, check if this array is Sorted
// (non-increasing or non-decreasing) and Rotated counter-clockwise. Note that
// input array may be sorted in either increasing or decreasing order, then rotated.
// A sorted array is not considered as sorted and rotated, i.e., there should be
// at least one rotation.

// Eg
// Input:
// N = 4
// arr[] = {3,4,1,2}
// Output: Yes
// Explanation: The array is sorted
// (1, 2, 3, 4) and rotated twice
// (3, 4, 1, 2).

// Eg
// Input:
// N = 3
// arr[] = {1,2,3}
// Output: No
// Explanation: The array is sorted
// (1, 2, 3) is not rotated.


#include <bits/stdc++.h>
using namespace std;

bool isincreasing(int a[], int l, int r)
{
    for(int i=l+1; i<=r; i++)
        if(a[i] < a[i-1])
            return false;
    return true;
}

bool isdecreasing(int a[], int l, int r)
{
    for(int i=l+1; i<=r; i++)
        if(a[i] > a[i-1])
            return false;
    return true;
}


bool checkRotatedAndSorted(int a[], int n)
{
    int min_index = 0, max_index = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i] < a[min_index])
            min_index = i;
        if(a[i] > a[max_index])
            max_index = i;
    }
    bool res = false;
    if(max_index == min_index-1)
    {
        if(a[0] < a[n-1])
        {
            res = false;
            goto x;
        }
        res = isincreasing(a, 0, max_index) && isincreasing(a, min_index, n-1);
    }
    x:
    if(min_index == max_index-1)
    {
        if(a[0] > a[n-1])
        {
            res = false;
            goto y;
        }
        res = isdecreasing(a, 0, min_index) && isdecreasing(a, max_index, n-1);
    }
    y:
    return res;
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
  cout<<checkRotatedAndSorted(a, n);
  return 0;
}
