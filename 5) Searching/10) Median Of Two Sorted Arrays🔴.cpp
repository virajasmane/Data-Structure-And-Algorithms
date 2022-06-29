// Given two sorted arrays of sizes N and M respectively. The task is to find
// the median of the two arrays when they get merged.

// Input:
// N = 5, M = 6
// arr[] = {1,2,3,4,5}
// brr[] = {3,4,5,6,7,8}
// Output: 4
// Explanation: After merging two arrays,
// elements will be as 1 2 3 3 4 4 5 5 6 7 8
// So, median is 4.

#include <bits/stdc++.h>
using namespace std;


float medianarr(vector<int> &a1, vector<int> &a2) // Naive solution
{
  vector<int> temp;
  temp.insert(temp.begin(), a1.begin(), a1.end());
  temp.insert(temp.end(), a2.begin(), a2.end());
  sort(temp.begin(), temp.end());
  int n = temp.size();
  if(n % 2 == 0)
    return float( ( temp[n/2 - 1] + temp[n/2] ) / 2 );
  else
    return temp[(n-1)/2];
  // Time Compelxity :- ( (n1+n2) * Log(n1+n2) )
  // Aux Space :- BigO(n)
}
//______________________________________________________________________________

// Effecient Solution
// We'll use binary search for effecint approach.
// always make sure that size of a1 is smaller than or equal to a2, if it is
// bigger then swap it.

float medianarrE(vector<int> &a1, vector<int> &a2, int n1, int n2)
{
  int start = 0, end = n1;
  while(start <= end)
  {
    int i1 = (start+end)/2;
    int i2 = (n1+n2+1)/2 - i1;

    int min1 = (i1 == n1) ? INT_MAX : a1[i1];
    int max1 = (i1 == 0) ? INT_MIN : a1[i1-1];

    int min2 = (i2 == n2) ? INT_MAX : a2[i2];
    int max2 = (i2 == 0) ? INT_MIN : a2[i2-1];

    if(max1 <= min2 && max2 <= min1)
    {
      if( (n1+n2) % 2 == 0 )
      {
        return  float ( max(max1, max2) + min(min1, min2)  / 2 ) ;
      }
      else
      {
        return max(max1, max2);
      }
    }
    else if(max1 > min2)
    {
      end = i1 - 1;
    }
    else
    {
      start = i1 + 1;
    }
  }
  // Time Compelxity :- BigO( Log(n1) )
  // Aux Space :- BigO(1)
}

int main()
{
  int n1, n2;
  cout<<"Enter the no of elements of a1\n";
  cin>>n1;
  vector<int> a1(n1);
  cout<<"Enter the elements of a1\n";
  for(auto &it: a1)
    cin>>it;
  cout<<"Enter the no of elements of a2\n";
  cin>>n2;
  vector<int> a2(n2);
  cout<<"Enter the elements of a2\n";
  for(auto &it: a2)
    cin>>it;
  cout<<medianarr(a1, a2);
  return 0;
}
