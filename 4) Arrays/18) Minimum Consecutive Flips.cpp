// We've to make minimum group flips to make the given binary array same
// Either 1 or 0 can be flipped.
// Eg I/P :- {1, 1, 0, 0, 0, 1}
//    O/P :- From 2 to 4

#include <bits/stdc++.h>
using namespace std;


// int minflip(bool a[], int n) //Naive Solution
// {
//
//   // Time Complexity :-
//   // Aux Space :-
// }
//______________________________________________________________________________

// Logic here is the difference between the 0's and 1's group will always be
// one or zero
// Eg 1 1 0 0 0 1 1 0 0 0    here two groups each of 1's and 0's, difference b/w groups is zero
//    1 0 0 0 1 1 1          here two groups of 1's and one group of 0's, difference b/w groups is one
// so we always flip the second group, either that group will be minimum or equal


void minflipE(bool a[], int n) //Effecient Solution
{
  for(int i=1; i<n; i++)
  {
    if(a[i] != a[i-1])
    {
      if(a[i] != a[0])
        cout<<"From "<<i<<" to ";
      else
        cout<<(i-1)<<"\n";
    }
  }
  if(a[0] != a[n-1])
    cout<<(n-1)<<"\n";
  // Time Complexity :- Theta(n)
  // Aux Space :- Theta(1)
}



int main()
{
  int n;
  cout<<"Enter N \n";
  cin>>n;
  bool a[n];
  cout<<"Enter the elements of array\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  minflipE(a, n);
  return 0;
}
