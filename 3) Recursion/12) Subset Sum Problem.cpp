#include <bits/stdc++.h>
using namespace std;

int countsubset(int arr[], int n, int sum)
{
  if(n==0)
    return (sum == 0) ? 1: 0;
  return countsubset(arr, n-1, sum) + countsubset(arr, n-1, sum-arr[n-1]);
  // Time Complexity :- Theta( pow(2,n) )
}

int main()
{
  int n,sum;
  cout<<"Enter The number of elements and the sum \n";
  cin>>n>>sum;
  int arr[n];
  cout<<"Enter the elements \n";
  for(int i=0; i<n; i++)
    cin>>arr[i];
  cout<<countsubset(arr, n, sum);
	return 0;
}
