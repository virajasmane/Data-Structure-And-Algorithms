#include<bits/stdc++.h>
using namespace std;

// Lomuto partition assumes that pivot is the last element, although it can be
// done so that the pivot is not the last.

// Is not an inplace algorithm

int LomutoPartition(vector<int> a, int low, int high, int pivot)
{
  int i = low - 1;
  for(int j=low; j<high; j++)
    if(a[j] < a[pivot])
    {
      i++;
      swap(a[j], a[i]);
    }
  swap(a[i+1], a[high]);
  return (i+1);
}
// Time Complexity :- O(n)
// Aux Space :- O(1)

int main()
{
  int n;
  cout<<"Enter the no of elements of the array\n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements of the array \n";
  for(auto &i: a)
    cin>>i;
  cout<<LomutoPartition(a, 0, n-1, n-1);
  return 0;
}
