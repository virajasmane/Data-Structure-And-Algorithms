
// Eg

// I/P :- data = {1, 2, 3, 4}, n = 4, k = 2
// O/P :- 6

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:
// 113
// Explanation:
// Allocation can be done in following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90}  Maximum Pages =113
// Therefore, the minimum of these cases is
// 113, which is selected as the output.

#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &data, int start, int end)
{
  int res = 0;
  for(int i=start; i<=end; i++)
    res += data[i];
  return res;
}
int minpages(vector<int> &data, int n, int k) // Naive Solution
{
  if(k == 1)
    return sum(data, 0, n-1);

  if(n == 1)
    return data[0];

  int res = INT_MAX;
  for(int i=1; i<n; i++)
    res = min( res, max( minpages(data, i, k-1), sum(data, i, n-1) ) );

  return res;
  // Time Compelxity :- exponential
  // Aux Space :-
}
//______________________________________________________________________________

// Apply Binary search, special case where I/P is not sorted and still we're using
// Bsearch.

bool isfeasible(vector<int> data, int n, int k, int ans)
{
  int req_stud = 1, sum = 0;
  for(int i=0; i<n; i++)
  {
    if(sum + data[i] > ans)
    {
      req_stud++;
      sum = data[i];
    }
    else
      sum += data[i];
  }
  return (req_stud <= k);
}

int minpagesE(vector<int> &data, int n, int k) // Effecient Solution
{
  int sum = 0, max_value = INT_MIN;
  for(int i=0; i<n; i++)
  {
    sum += data[i];
    max_value = max(max_value, data[i]);
  }

  int low = max_value, high = sum, result = 0;
  while(low <= high)
  {
    int mid = (low+high)/2;
    if(isfeasible(data, n, k, mid))
    {
      result = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return result;
  // Time Complexity :- O( n*Log(sum - max_value) )
  // Aux Space :- O(1)
}

int main()
{
  int n;
  cout<<"Enter the no of elements \n";
  cin>>n;
  vector<int> data(n);
  cout<<"Enter the elements\n";
  for(auto &it: data)
    cin>>it;
  int k;
  cout<<"Enter the no of students \n";
  cin>>k;
  cout<<minpages(data, n, k);
  return 0;
}
