// Define Inversion
// A pair(a[i], a[j]) forms an inversion when i < j and a[i] > a[j].

// I/P :- {2, 4, 1, 3, 5}
// O/P :- 3
// Inversion pairs are (4, 1), (4, 3), (2, 1)

#include<bits/stdc++.h>
using namespace std;


int CountInversion(vector<int> a, int n)
{
  int result = 0;
  for(int i=0; i<n-1; i++)
    for(int j=i+1; j<n; j++)
      if(a[i] > a[j])
        result++;
  return result;
}
// Time Complexity :- O(n^2)
// Aux Space :- O(1)
//______________________________________________________________________________

// Effecient Solution

int CountandMerge(vector<int> a, int left, int mid, int right)
{
  int n1 = mid-left+1, n2 = right-mid;
  vector<int> leftarr(n1);
  vector<int> rightarr(n2);
  for(int i=0; i<n1; i++)
    leftarr[i] = a[left+i];
  for(int i=0; i<n2; i++)
    rightarr[i] = a[mid+1+i];

  int result = 0, i = 0, j = 0, k = left;
  while(i < n1 && j < n2)
  {
    if(leftarr[i] <= rightarr[j])
    {
      a[k] = leftarr[i];
      i++;
    }
    else
    {
      a[k] = rightarr[j];
      j++;
      result = result + (n1 - i); /* In this else case it means
      rightarr[j] < leftarr[i] so since leftarr and rightarr is sorted rightarr[j]
      will be smaller than all the elements after leftarr[i] too
      so all that pairs are inversion too so we count multiple inversions
      at a time that's why sorting while counting inversions is important. */
    }
    k++;
  }
  while(i < n1)
  {
    a[k] = leftarr[i];
    i++;
    k++;
  }
  while(j < n2)
  {
    a[k] = rightarr[j];
    j++;
    k++;
  }
  return result;
}

int CountInversion(vector<int> a, int left, int right)
{
  int result = 0;
  if(left < right)
  {
    int mid = left + (right - left) / 2;
    result += CountInversion(a, left, mid);
    result += CountInversion(a, mid+1, right);
    result += CountandMerge(a, left, mid, right);
  }
  return result;
}
// Time Complexity :- O(nLogn)
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
  cout<<CountInversion(a, 0, n-1);
  return 0;
}
