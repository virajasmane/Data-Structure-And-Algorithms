#include<bits/stdc++.h>
using namespace std;


void unionN(vector<int> &a, vector<int> &b, int n, int m) //Naive Solution
{
  vector<int> c(m+n);
  for(int i=0; i<n; i++)
    c[i] = a[i];
  for(int i=0; i<m; i++)
    c[n+i] = b[i];

  sort(c.begin(), c.end());

  for(int i=0; i<m+n; i++)
    if(i == 0 || c[i] != c[i-1])
      cout<<c[i]<<" ";
}
// Time Complexity:- O( (m+n) * Log(m+n) )
// Aux Space :- O(m+n)

//______________________________________________________________________________
// Effecient Solution
// For non repeating elements in the array

void unionNE(vector<int> &a, vector<int> &b, int n, int m)
{
  int i=0, j=0;
  while(i<n && j<m)
  {
    if(i > 0 && a[i] == a[i-1])
    {
      i++;
      continue;
    }
    if(j > 0 && b[j] == b[j-1])
    {
      j++;
      continue;
    }
    if(a[i] < b[j])
    {
      cout<<a[i]<<" ";
      i++;
    }
    else if(b[j] < a[i])
    {
      cout<<b[j]<<" ";
      j++;
    }
    else
    {
      cout<<a[i]<<" ";
      i++;
      j++;
    }
  }
  while(i<n)
  {
    if(i > 0 && a[i] != a[i-1])
      cout<<a[i]<<" ";
    i++;
  }
  while(j<m)
  {
    if(j > 0 && b[j] != b[j-1])
      cout<<b[j]<<" ";
    j++;
  }
}
// Time Complexity :- O(m+n)
// Aux Space O(1)

//______________________________________________________________________________
// Function For repeating elements in the array.
// Link :- https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1/?track=DSASP-Sorting&batchId=154#
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> result;

        int max1 = arr1[n-1];
        int max2 = arr2[m-1];
        int ans = 0;

        if(max1 > max2)
            ans = max1;
        else
            ans = max2;

        int count[ans+1] = {0};

        result.push_back(arr1[0]);
        ++count[arr1[0]];

        for(int i=1; i<n; i++)
        {
            if(arr1[i] != arr1[i-1])
                result.push_back(arr1[i]);
            ++count[arr1[i]];
        }

        for(int j=0; j<m; j++)
        {
            if(count[arr2[j]] == 0)
                result.push_back(arr2[j]);
            ++count[arr2[j]];
        }

        sort(result.begin(), result.end());

        return result;
    }


int main()
{
  int n;
  cout<<"Enter the no of elements of 1st array\n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements of 1st array \n";
  for(auto &i: a)
    cin>>i;
  int m;
  cout<<"Enter the no of elements of 1st array\n";
  cin>>m;
  vector<int> b(m);
  cout<<"Enter the elements of 1st array \n";
  for(auto &i: b)
    cin>>i;
  unionNE(a, b, n, m);
  return 0;
}
