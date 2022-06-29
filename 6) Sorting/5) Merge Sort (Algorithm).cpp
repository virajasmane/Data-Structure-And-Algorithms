#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
  int n1 = mid - low + 1, n2 = high - mid; // The low, mid and high might not necessarily be the first, mid and last element of the array, ie why +1 in n1.
  vector<int> left(n1);
  vector<int> right(n2);

  for(int i=0; i<n1; i++)
    left[i] = arr[low+i];

  for(int j=0; j<n2; j++)
    right[j] = arr[mid+j+1]; // Line 6 to 12 is setting up the aux arrays

  int i=0, j=0, k=low;
  while(i < n1  &&  j < n2)
  {
    if(left[i] <= right[j])
    {
      arr[k] = left[i];
      i++;
      k++;
    }
    else
    {
      arr[k] = right[j];
      j++;
      k++;
    }
  }
  while(i < n1)
  {
    arr[k] = left[i];
    i++;
    k++;
  }
  while(j < n2)
  {
    arr[k] = right[j];
    j++;
    k++;
  }
  // Time Complexity & Aux Space :- Theta(n)
}

void merge_sort(vector<int> &arr, int l, int h)
{
  if(h > l) // This makes sure that there are atleast 2 elements in the array
  {
    int m = l + (h - l)  / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, h);
    merge(arr, l, m, h);
  }
}


int main()
{
  int n;
  cout<<"Enter the no of elements \n";
  cin>>n;
  vector<int> arr(n);
  cout<<"Enter the elements \n";
  for(auto &i: arr)
    cin>>i;
  merge_sort(arr, 0, n-1);
  for(auto &i: arr)
    cout<<i<<" ";
  return 0;
}
