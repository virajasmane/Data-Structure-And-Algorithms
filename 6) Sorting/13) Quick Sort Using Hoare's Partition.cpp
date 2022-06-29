#include<bits/stdc++.h>
using namespace std;

int Hoarepartition(vector<int> &a, int low, int high)
{
  int i = low - 1, j = high + 1, pivot = low;
  while(1)
  {
    do
    {
      i++;
    } while(a[i] < a[pivot]);

    do
    {
      j--;
    } while(a[pivot] < a[j]);

    if(j <= i)
      return j;
    swap(a[i], a[j]);
  }
}

void QuickSort(vector<int> &a, int low, int high)
{
  if(low < high)
  {
    int partition = Hoarepartition(a, low, high);
    QuickSort(a, low, partition);
    QuickSort(a, partition + 1, high);
  }
}
// Time Complexity :- nLog(n)
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
