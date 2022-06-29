// Eg of Circular Subarray
// {10, 5, -5}
// All Circular subarrays are as follows
// Normal Subarrays :- {10}, {5}, {-5}, {10, 5}, {5, -5}, {10, 5, -5}
// Circular Subarrays :- {5, -5, 10}, {-5, 10}, {-5, 10, 5}

#include <bits/stdc++.h>
using namespace std;


int maxcircularsum(int a[], int n)
{
  int res = 0;
  for(int i=0; i<n; i++)
  {
    int currmax = a[i], currsum = a[i];
    for(int j=1; j<n; j++)
    {
      int index = (i+j)%n;
      currsum += a[index];
      currmax = max(currmax, currsum);
    }
    res = max(res, currmax);
  }
  return res;
  // Time Complexity :- BigO(n^2)
  // Aux Space :- Theta(1)
}
//______________________________________________________________________________

// Effecient Solution :- BigO(n)
// IDEA :- Return the max of the following two
        // 1) Maximum sum of the normal subarray (By Kadane's Algorithm)
        // 2) Maximum sum of the circular subarray (How to find this ?)
             // So the idea is to find the minimum sum subarray and subtract
             // it from the total sum of array elements.
             // Note :- This sum does not have to be maximum Circular
             //         sum, but if there is a circular sum which is Maximum
             //         then it will defiinitely give you.


// This is self written code but it will fail for all negative numbers
// Eg :- I/P -5, -3
// Ideal O/P :- -3
// This Code O/P :- 0
// Because if all nos are negative the max sum should be negative, but the
// "sum(a, n)-minsum(a, n)" part will always give ans "0" and max of 0 and any
// negative number will be zero.
int maxsum(int a[], int n)
{
  int currsum = a[0], res = a[0];
  for(int i=1; i<n; i++)
  {
    currsum = max(currsum+a[i], a[i]);
    res = max(res, currsum);
  }
  return res;
}

int minsum(int a[], int n)
{
  int currsum = a[0], res = a[0];
  for(int i=1; i<n; i++)
  {
    currsum = min(currsum+a[i], a[i]);
    res = min(res, currsum);
  }
  return res;
}

int sum(int a[], int n)
{
  int res = 0;
  for(int i=0; i<n; i++)
    res += a[i];
  return res;
}

int maxcircularsumEI(int a[], int n)
{
  return max(maxsum(a, n), sum(a, n)-minsum(a, n));
}
//______________________________________________________________________________

// This is the correct code.
int maxcircularsumE(int a[], int n)
{
  if(maxsum(a, n) < 0)  //This if condition corrects the wrong of the above code
    return maxsum(a, n); // It means if max normal is less than zero all the nos
                       // are less than zero and the ans is just maxnormal then.
  return max(maxsum(a, n), sum(a, n) - minsum(a, n));
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
  cout<<maxcircularsumE(a, n);
  return 0;
}
