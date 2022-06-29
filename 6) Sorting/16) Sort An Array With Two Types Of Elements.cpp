// Here different types can be odd even, positive negative or 0s and 1s etc.
#include<bits/stdc++.h>
using namespace std;

// Naive solution will be like naive partitioning.

// Effecient Solution is like hoare or lomuto partitioning.
void sort_diff_type_elements(vector<int> &a, int n)
{
  int i = -1, j = n;
  while(1)
  {
    do
    {
      i++;
    } while(a[i] <= 0);
    do
    {
      j--;
    } while(0 < a[j]);
    if(j <= i)
      return;
    swap(a[i], a[j]);
  }
}
// Time Complexity :-
// Space Complexity :-

int main()
{
  int n;
  cout<<"Enter the no of elements of the array\n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements of the array \n";
  for(auto &i: a)
    cin>>i;
  sort_diff_type_elements(a, n);
  for(int &var: a)
    cout<<var<<" ";
  return 0;
}
