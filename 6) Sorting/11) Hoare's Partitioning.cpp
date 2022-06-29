#include<bits/stdc++.h>
using namespace std;

// Hoare's partition considers 1st element as the pivotand it returns the index
// of the element which is smaller than the pivot and index+1 and elements after
// that has element greater than the pivot.

// Hoare's partition doesnt compulsorily place the pivot element at its right
// place, thats the difference b/w hoare's partition and lomuto partition.

// In general Hoare partition takes much less comparisions than lomuto partition
// and works much btter than lomuto partition.
// So Hoare's partition is much faster (3 times faster) than lomuto parititon.

// In a interesting corner case when all the elements of the array are same,
// the Hoare partition swaps the elements which is why it is not inplace
// which is why quick sort is generally not inplace sorting algorithm.

int HoarePartition(vector<int> a, int low, int high, int pivot)
{
  int i = low-1, j = high+1;
  while(1)
  {
    do
    {
      i++;
    } while(a[i] < pivot);
    do
    {
      j--;
    } while(a[j] > pivot);
    if(i>=j)
      return j;
    swap(a[i], a[j]);
  }
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
  cout<<HoarePartition(a, 0, n-1, a[0]);
  return 0;
}
