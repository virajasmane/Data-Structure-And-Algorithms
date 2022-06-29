// Popular Amazon interview question(The triplet question).

// Question :- Given a sorted array and a sum find a pair of elements which which equals
// the given sum.
// The two pointer technique for a Sorted array only, for unsorted array we've
// to use hashing.

#include <bits/stdc++.h>
using namespace std;


bool issum(int a[], int n, int x) // Naive solution
{
  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
      if(a[i]+a[j] == x)
        return true;
  return false;
  // Time Complexity :-
  // Aux Space :-
}
//______________________________________________________________________________

bool issumE(int a[], int n, int x) // Two-pointer technique
{
  int left = 0, right = n-1;
  while(left < right)
  {
    if(a[left] + a[right] == x)
      return true;
    else if(a[left] + a[right] < x)
      left++;
    else
      right--;
  }
  return false;
}
//______________________________________________________________________________

// Variation Question :- Given a sorted array and a sum find triplets with the given sum.
// this question can also be solved in n^2 if the array is unsorted.
bool issumEV(int a[], int n, int x)
{
  for(int i=0; i<n; i++)
  {
    int left = i+1, right =  n-1;
    while(left < right)
    {
      if(a[i] + a[left] + a[right] == x)
        return true;
      else if(a[i] + a[left] + a[right] < x)
        left++;
      else
        right--;
    }
  }
  return false;
  // Time Compelxity :- BigO(n^2)
}

int main()
{
  int n, x;
  cout<<"Enter no of elements \n";
  cin>>n;
  int a[n];
  cout<<"Enter the elements\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<"Enter the value of x\n";
  cin>>x;
  cout<<issumEV(a, n, x);
  return 0;
}
