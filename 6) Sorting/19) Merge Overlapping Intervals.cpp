//Link :- https://practice.geeksforgeeks.org/tracks/DSASP-Sorting/?batchId=154#

#include<bits/stdc++.h>
using namespace std;

struct Interval
{
  int start;
  int end;
};

bool CompareInterval(Interval a, Interval b)
{
  return a.start < b.start;
}

void MergeInterval(vector<Interval> &a, int n) // Naive Solution
{
  sort(a.begin(), a.end(), CompareInterval);
  int result = 0;
  for(int i=1; i<n; i++)
  {
    if(a[i].start <= a[result].end) // Condition to check if pairs ovelap or not
    {
      a[result].end = max(a[result].end, a[i].end);
      a[result].start = min(a[result].start, a[i].start);
    }
    else
    {
      result++;
      a[result] = a[i];
    }
  }
  for(int i=0; i<=result; i++)
    cout<<a[i].start<<" "<<a[i].end<<"\n";
}
// Time Complexity :- O(NlogN)
// Space Complexity :- O(1)

int main()
{
  int n;
  cout<<"Enter the no of elements of the array\n";
  cin>>n;
  vector<Interval> a(n);
  cout<<"Enter the input \n";
  for(auto &var: a)
  {
    cin>>var.start;
    cin>>var.end;
  }
  MergeInterval(a, n);

  return 0;
}
