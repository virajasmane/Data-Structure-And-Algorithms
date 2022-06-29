
#include <bits/stdc++.h>
using namespace std;


int squareroot(int n) // Naive solution
{
  int i = 1;
  while(i*i <= n)
    i++;
  return i-1;
  // Time Complexity :- BigO( sqrt(n) )
  // Aux Space :- BigO(1)
}
//______________________________________________________________________________

// Idea is to use binary search.

int squarerootE(int n)
{
  int low = 1, high = n, ans = -1;
  while(low <= high)
  {
    int mid = (low+high)/2;
    int midsq = mid*mid;
    if(midsq == n)
      return mid;
    else if(midsq > n)
      high = mid -  1;
    else
    {
      low = mid + 1;
      ans = mid;
    }
  }
  return ans;
  // Time Complexity :- BigO( Log(n) )
  // Aux Space :- Theta(1)
}


int main()
{
  int n;
  cout<<"Enter N \n";
  cin>>n;
  cout<<squarerootE(n);
  return 0;
}
