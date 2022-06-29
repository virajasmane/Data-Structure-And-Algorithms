#include<bits/stdc++.h>
using namespace std;

int LomutoPartition(vector<int> &a, int low, int high)
{
  int i = low-1, pivot = a[high];
  for(int j=low; j<high-1; j++)
  {
      if(a[j] < pivot) //since in lomuto partition pivot is the last element ie element at index high
      {
        i++;
        swap(a[i], a[j]);
      }
  }
  swap(a[i+1], a[high]);
  return i+1;
}

void QuickSort(vector<int> &a, int low, int high)
{
  if(low < high)
  {
    int partition = LomutoPartition(a, low, high);
    QuickSort(a, low, partition - 1);
    QuickSort(a, partition + 1, high);
  }
}
// Time Complexity :- O( nLogn )
// Aux Space :- O(n)

int main()
{
  int n;
  cout<<"Enter the no of elements of the array\n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements of the array \n";
  for(auto &i: a)
    cin>>i;
  QuickSort(a, 0, n-1);
  for(int &i: a)
    cout<<i<<"  ";
  return 0;
}
