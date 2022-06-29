// Question
// Given an array solve the query in Theta(1) time
// Eg I/p :- arr = {2, 8, 3, 9, 6, 5, 4}
//           getsum(0, 2)
//           getsum(1, 3)
//    O/P :- 13
//           20

// So we use prefix sum technique we calculate a prefix sum array in Theta(n)
// time and then use it to find getsum of given indexs in Theta(1) time.

#include <bits/stdc++.h>
using namespace std;

int prefixsum(int a[], int n, int l, int r)
{
  int prefix_sum[n];
  prefix_sum[0] = a[0];
  for(int i=1; i<n; i++)
  {
    prefix_sum[i] = prefix_sum[i-1] + a[i];
  }
  return (l==0) ? prefix_sum[r] : prefix_sum[r]-prefix_sum[l-1];
  // Time Complexity :-Theta(1)
  // Aux Complexity :- Theta(n)
}


//______________________________________________________________________________



int main()
{
  int n, l ,r;
  cout<<"Enter N \n";
  cin>>n;
  int a[n];
  cout<<"Enter the elements of array\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<"Enter 2 index of which you want the sum of \n";
  cin>>l>>r;
  cout<<prefixsum(a, n, l, r);

  return 0;
}
