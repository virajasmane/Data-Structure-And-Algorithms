#include <bits/stdc++.h>
using namespace std;

// Eg
// I/P :- a[] = {10, 15, 20, 5, 30}
//        b[] = {30, 5, 30, 80}
// O/P :- 2


// I/P :- a[] = {10, 20}
//        b[] = {20, 30}
// O/P :- 1

// Naive Solution
int Intersection_Of_Arrays(vector<int> vector1, vector<int> vector2)
{
  int result = 0;
  for(int i=0; i<vector1.size(); i++)
  {
    bool isEqual = false; // Line 20 through 30 checks if the element is already seen or not.
    for(int j=0; j<i; j++)
    {
      if(vector1[i] == vector1[j])
      {
        isEqual = true;
        break;
      }
    }
    if(isEqual == true)
      continue;
    for(int j=0; j<vector2.size(); j++)
    {
      if(vector1[i] == vector2[j])
      {
        result++;
        break;
      }
    }
  }
  return result;
}
// Time Complexity :- O(m*(n+m))
// Aux Space :- O(1)
//______________________________________________________________________________

// Effecient Solution 1

// 1) Insert all the elements of a[] in s_a unordered_set.
// 2) Insert all the elements of b[] in s_b  unordered_set.
// 3) Now traverse through s_a and increment the count for elements
//    that are present in the s_b also.


int ES1_Intersection_Of_Arrays(vector<int> vector1, vector<int> vector2)
{
  int result = 0;
  unordered_set<int> s_a(vector1.begin(), vector1.end());
  unordered_set<int> s_b(vector2.begin(), vector2.end());

  for(int i=0; i<vector1.size(); i++)
  {
    if(s_b.find(s_a[i]) != s_b.end())
      result++;
  }

  return result;
}
// Time Complexity :- 0(m+n)
// Aux Space :- O(m+n)
//______________________________________________________________________________

// Effecient Solution 2

// 1) Insert all the elements of a[] in s_a unordered_set.
// 2) Traverse through b[], search for every element b[i] in s_a, if present
//    a) Increment result
//    b) Remove b[i] from s_a (to avoid duplicates.)

int ES2_Intersection_Of_Arrays(vector<int> vector1, vector<int> vector2)
{
  int result = 0;
  unordered_set<int> s_a(vector1.begin(), vector1.end());
  for(int i=0; i<vector2.size(); i++)
  {
    if(s_a.find(vector2[i]) != s_a.end())
    {
      result++;
      s_a.erase(vector2[i]);
    }
  }
  return result;
}
// Time Complexity :- 0(m+n)
// Aux Space :- O(m)



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

  cout<<ES2_Intersection_Of_Arrays(vector1, vector2);


  return 0;
}
