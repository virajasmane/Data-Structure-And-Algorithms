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

//Effecient Solution

int E_Intersection_Of_Arrays(vector<int> vector1, vector<int> vector2)
{
  int result = 0;


  return result;
}


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

  cout<<E_Intersection_Of_Arrays(vector1, vector2);


  return 0;
}
