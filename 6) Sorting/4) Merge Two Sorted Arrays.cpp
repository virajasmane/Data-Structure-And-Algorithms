#include<bits/stdc++.h>
using namespace std;

void merge_sort(vector<int> &arr1, int n1, vector<int> &arr2, int n2)
{
  int index1 = 0, index2 = 0;
  while(index1 < n1 && index2 < n2)
  {
    if(arr1[index1] <= arr2[index2])
    {
      cout<<arr1[index1]<<" ";
      index1++;
    }
    else
    {
      cout<<arr2[index2]<<" ";
      index2++;
    }
  }
  while(index1 < n1)
  {
    cout<<arr1[index1]<<" ";
    index1++;
  }
  while(index2 < n2)
  {
    cout<<arr2[index2]<<" ";
    index2++;
  }
  // Time Complexity :- Theta(n1+n2)
  // Aux Space :- O(1)
}
//______________________________________________________________________________

/* This function is a complex version of the above discussed problem on
Merge Sort.
Here we take a single array with three points namely, the lower, the middle
and the highest point. The elements from the lower to the middle are sorted
and the elements from the (middle+1) to the higher are sorted. The task is to
merge these two sorted parts into one. */

// where low <= mid and mid+1 < high, ghat means there will atleast be 2 elements.
void merge(vector <int> &arr, int low, int mid, int high)
{
  int n1 = mid - low + 1, n2 = high - mid; // The low, mid and high might not necessarily be the first, mid and last element of the array.
  vector<int> left(n1);
  vector<int> right(n2);
  for(int i=0; i<n1; i++)
    left[i] = arr[low+i];
  for(int i=0; i<n2; i++)
    right[i] = arr[mid + i + 1]; // Line 45 to 51 is setting up the aux arrays
  int i=0, j=0, k=0;
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

int main()
{
  int n1, n2;
  cout<<"Enter the no of elements of arr1 \n";
  cin>>n1;
  vector<int> arr1(n1);
  cout<<"Enter the elements \n";
  for(auto &i: arr1)
    cin>>i;
  cout<<"Enter the no of elements of arr1 \n";
  cin>>n2;
  vector<int> arr2(n2);
  cout<<"Enter the elements of arr2 \n";
  for(auto &i: arr2)
    cin>>i;
  merge_sort(arr1, n1, arr2, n2);
  return 0;
}
