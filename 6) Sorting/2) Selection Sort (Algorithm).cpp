#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr, int n)
{
  for(int i=0; i<n-1; i++)
  {
    int min_index = i;
    for(int j=i+1; j<n; j++)
    {
      if(arr[j] < arr[min_index])
        min_index = j;
    }
    swap(arr[i], arr[min_index]);
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
  selection_sort(arr, n);
  for(auto &i: arr)
    cout<<i<<" ";
  return 0;
}
