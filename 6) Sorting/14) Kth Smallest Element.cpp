#include<bits/stdc++.h>
using namespace std;

int lomutopartition(vector<int> &a, int low, int high)
{
  int i = low - 1, pivot = high;
  for(int j=low; j<high; j++)
    if(a[j] < a[pivot])
    {
      i++;
      swap(a[j], a[i]);
    }
  swap(a[i+1], a[high]);
  return (i+1);
}

int hoarepartition(vector<int> &a, int low, int high)
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

void quicksort(vector<int> &a, int low, int high)
{
  if(low < high)
  {
    int partition = hoarepartition(a, low, high);
    quicksort(a, low, partition);
    quicksort(a, partition+1, high);
  }
}


int KthSmallest(vector<int> &a, int n, int k)
{
  quicksort(a, 0, n-1); // can also use inbulit sort function ie sort(a.begin(), a.end());
  return a[k-1];
}
// Time Complexity :- O(NlogN)
// Aux Space :-
//______________________________________________________________________________

// Uses the Lomutopartition technique to find the Kth smallest element.
int KthSmallestE(vector<int> &a, int n, int k)
{
  if(k > n)
    return -1;
  int low = 0, high = n-1;
  while(low <= high)
  {
    int partition = lomutopartition(a, low, high);
    if(partition == k-1)
      return a[partition];
    else if(partition < k-1)
      low = partition + 1;
    else
      high = partition - 1;
  }
}

int main()
{
  int n, k;
  cout<<"Enter the no of elements of the array\n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements of the array \n";
  for(auto &i: a)
    cin>>i;
  cout<<"Enter k \n";
  cin>>k;
  cout<<KthSmallestE(a, n, k);
  return 0;
}
