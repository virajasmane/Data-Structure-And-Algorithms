// Microsoft Question

// Input:
// N = 4
// arr[] = {4, 8, 12, 16}
// Output: 8
// Explanation:
// Pair (8,12) has the Maximum AND Value 8.
// Explanation :- https://www.youtube.com/watch?v=s5wC7RrxDzE&ab_channel=sKSama

#include <bits/stdc++.h>
using namespace std;

int checkbit(int pattern, int arr[], int n)
{
  int count=0;
  for(int i=0; i<n; i++)
    if((pattern & arr[i]) == pattern)
      count++;
  return count;
}

int maxANDvalue(int arr[], int n)
{
  int res=0,count;
  for(int bit=31; bit>=0; bit--)
  {
    count = checkbit(res | (1<<bit), arr, n);
    if(count>=2)
      res |= (1<<bit);
  }
  return res;
}

int main()
{
  int n;
  cout<<"Enter the size of the array\n";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements of the array\n";
  for(int i=0; i<n; i++)
    cin>>arr[i];
  cout<<maxANDvalue(arr, n);
	return 0;
}
