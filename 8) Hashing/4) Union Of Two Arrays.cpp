#include <bits/stdc++.h>
using namespace std;


int Union_Of_Arrays(vector<int> a, vector<int> b)
{
  unordered_set<int> s(a.begin(), a.end());

  for(auto &i: b)
    s.insert(i);

  return s.size();
}
// Time Complexity :- 0(m+n)
// Aux Space :- O(m+n)

int main()
{
  int length1, length2;

  cout<<"Length of 1st Vector \n";
  cin>>length1;
  vector<int> vector1(length1);

  cout<<"Enter the elements of the 1st Vector \n";
  for(auto &i: vector1)
    cin>>i;

  cout<<"Length of 2nd Vector \n";
  cin>>length2;
  vector<int> vector2(length2);

  cout<<"Enter the elements of the 2nd Vector \n";
  for(auto &i: vector2)
    cin>>i;

  cout<<"Answer is :- "<<Union_Of_Arrays(vector1, vector2);


  return 0;
}
