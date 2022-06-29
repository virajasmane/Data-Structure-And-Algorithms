#include<bits/stdc++.h>
using namespace std;


int MinDiff(vector<int> &a, int n) // Naive Solution
{
    int result = INT_MAX;
    for(int i=1; i<n; i++)
      for(int j=0; j<i; j++)
        result = min(result, abs(a[i] - a[j]));
    return result;
}
// Time Complexity :- O(n^2)
// Space Complexity :- O(1)
//______________________________________________________________________________

// Effecient Solution
int MinDiffE(vector<int> &a, int n) // Naive Solution
{
  int result = INT_MAX;
  sort(a.begin(), a.end());
  for(int i=1; i<n; i++)
    result = min(result, a[i] - a[i-1]);
  return result;
}
// Time Complexity :- O(NlogN)
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
  cout<<MinDiffE(a, n);

  return 0;
}
