
// input vector = {1, 3, 2, 4, 6, 5, 7, 3}, n= 8;
// OP :- 3

#include <bits/stdc++.h>
using namespace std;


int findrepeatingelement(vector<int> &a)
{
  int slow = a[0] , fast = a[0] ;
  do // Phase-I
  {
    slow = a[slow] ;
    fast = a[a[fast]] ;
  } while(slow != fast);

  slow = a[0] ;

  while(slow != fast) // Phase-II
  {
    slow = a[slow] ;
    fast = a[fast] ;
  }
  return slow ; // even if you return fast it doesnt matter, both are same.
  // Time Compelxity  BigO(n)
  // Aux Space :- BigO(1)
}


int main()
{
  int n;
  cout<<"Enter the no of elements \n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements\n";
  for(auto &it: a)
    cin>>it;
  cout<<findrepeatingelement(a);
  return 0;
}
