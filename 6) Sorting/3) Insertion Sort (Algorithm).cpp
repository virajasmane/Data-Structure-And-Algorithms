#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr, int n)
{
  for(int i=1; i<n; i++)
  {
    int key = arr[i];
    int j = i-1;
    while(j>=0 && arr[j] > key)
    {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
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
  insertion_sort(arr, n);
  for(auto &i: arr)
    cout<<i<<" ";
  return 0;
}
