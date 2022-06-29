#include<bits/stdc++.h>
using namespace std;



int minDiff(vector<int> &a, int n, int m)
{
  if(m < n)
  {
    sort(a.begin(), a.end());
    int res = a[m-1] - a[0];
    for(int i=0; i+m-1<n; i++)
      res = min(res, a[i+m-1] - a[i]);
    return res;
  }
  return -1;
}
// Time Complexity :- O(NlogN)
// Space Complexity :- O(1)

int main()
{
  int n, m;
  cout<<"Enter the no of elements of the array\n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements of the array \n";
  for(auto &i: a)
    cin>>i;
  cout<<"Enter m \n";
  cin>>m;
  cout<<minDiff(a, n, m);
  return 0;
}
