// Many types of problems can be asked here folowing are 3 examples.

// 1) Sort an array of 0s, 1s and 2s. (Below is the code of this problem)
//     I/P : a[] = {0, 2, 1, 2 ,0}
//     O/P : a[] = {0, 0, 1, 2, 2}

// 2) Three way partitioning
//     I/P : a[] = {2, 1, 2, 20, 10, 20, 1}, pivot = 2
//     O/P : a[] = {1, 1, 2, 2, 20, 10, 20}

// 3) Paritition around a range
//     I/P : a[] = {10, 5, 6, 3, 20, 9, 40}, range = [5, 10]
//     O/P : a[] = {3, 5, 6, 9, 10, 20, 40}

#include<bits/stdc++.h>
using namespace std;

// Dutch National Flag Algorithm


void sort_diff_type_elements(vector<int> &a, int n)
{
  int low = 0, mid = 0, high = n-1;
  while(mid <= high)
  {
     if(a[mid] == 0)
     {
       swap(a[low], a[mid]);
       low++;
       mid++;
     }
     else if(a[mid] == 1)
      mid++;
    else
    {
      swap(a[mid], a[high]);
      high--;
    }
  }
}
// Time Complexity :- O(n) (Only one traversal unlike 4 traversal of naive partitioning)
// Space Complexity :- O(1)

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
