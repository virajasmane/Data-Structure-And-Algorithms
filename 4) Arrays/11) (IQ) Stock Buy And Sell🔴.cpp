// Amazon, DE Shaw, Directi, FLipkart, Microsoft,
// PayTm, Google, Media.net, Walmart, MMT Question.
// Warm up or Follow up problem that might be asked in an interview.

#include <bits/stdc++.h>
using namespace std;

int stockbuysell(int a[], int start, int end) // Naive Solution
{
  if(start >= end)
    return 0;
  int profit = 0;
  for(int i=start; i<end; i++)
    for(int j=i+1; j<=end; j++)
      if(a[i] < a[j])
      {
        int currprofit = (a[j]-a[i]) + stockbuysell(a, start, i-1) + stockbuysell(a, j+1, end);
        profit = max(profit, currprofit);
      }
  return profit;
  // Time Complexity :-
  // Aux Space :-
}

//______________________________________________________________________________

int stockbuysell(int a[], int n) //Effecient Solution
{
  int profit = 0;
  for(int i=1; i<n; i++)
    if(a[i] > a[i-1])
      profit += (a[i] - a[i-1]);
  return profit;
  // Time Complexity :- Theta(n)
  // Aux Space :- Theta(1)
}


int main()
{
  int n;
  cout<<"Enter N \n";
  cin>>n;
  int a[n];
  cout<<"Enter the elements of array\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<stockbuysell(a, n);
  return 0;
}
