#include<bits/stdc++.h>
using namespace std;

void BucketSort(vector<int> &a, int n, int k)
{
  int max_value = *max_element(a.begin(), a.end());
  max_value++; /* To avoid making an extra bucket. */

  vector<vector<int>> bucket(k);
  for(int i=0; i<n; i++)
  {
    int bucket_index = k * a[i] / max_value;
    bucket[bucket_index].push_back(a[i]);
  }

  for(int i=0; i<k; i++)
    sort(bucket[i].begin(), bucket[i].end());

  int index = 0;
  for(int i=0; i<k; i++)
    for(int j=0; j<bucket[i].size(); j++)
      a[index++] = bucket[i][j];
}
// Time Complexity :- Best Case O(n)
// Aux Space :- O(n)

int main()
{
  int n, k;
  cout<<"Enter the no of elements of the array\n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements of the array \n";
  for(auto &i: a)
    cin>>i;
  cout<<"Enter the no of Buckets\n";
    cin>>k;
  BucketSort(a, n, k);
  for(auto &i: a)
    cout<<i<<" ";
  return 0;
}
