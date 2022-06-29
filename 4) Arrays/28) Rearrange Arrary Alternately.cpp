// Question
// Given a sorted array of positive integers. Your task is to rearrange  the array
// elements alternatively i.e first element should be max value, second should be
// min value, third should be second max, fourth should be second min and so on.
// Eg
// Input:
// N = 6
// arr[] = {1,2,3,4,5,6}
// Output: 6 1 5 2 4 3
// Explanation: Max element = 6, min = 1,
// second max = 5, second min = 2, and
// so on... Modified array is : 6 1 5 2 4 3.

#include <bits/stdc++.h>
using namespace std;

void rearrange(int *a, int n)
{
    int me = a[n-1]+1, maxe = n-1, mine = 0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            a[i] = a[i] + a[maxe] % me * me;
            maxe--;
        }
        else
        {
           a[i] = a[i] + a[mine] % me * me;
           mine++;
        }
    }
    for(int i=0; i<n; i++)
        a[i] /= me;

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
  rearrange(a, n);
  for(int i=0; i<n; i++)\
    cout<<a[i]<<" ";
  return 0;
}
