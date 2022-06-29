#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr, int n)
{
  for(int i=0; i<n-1; i++)
  {
    bool swapped = false;
    for(int j=0; j<n-i-1; j++) /* We can further optimize this loop by replacing j<n-1 by j<n-i-1 because if we're on ith element, i elements are already fixed at the last position.*/
    {
      if(arr[j] > arr[j+1])
      {
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    if(swapped == false)
      break;
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
  bubble_sort(arr, n);
  for(auto &i: arr)
    cout<<i<<" ";
  return 0;
}
