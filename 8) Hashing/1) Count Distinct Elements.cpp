#include <bits/stdc++.h>
using namespace std;

// Eg
// I/P :- {1, 2, 2, 3, 4}
// O/P :- 4

// I/P :- {10, 10, 10}
// O/P :- 1

// Naive Solution
int Count_Distinct_Elements(vector<int> vector)
{
  int No_of_Dist_elements = 0;

  for(int i=0; i<vector.size(); i++)
  {
    bool isEqual = false;
    for(int j=0; j<i; j++)
    {
      if(vector[i] == vector[j])
        isEqual = true;
    }
    if(isEqual == false)
      No_of_Dist_elements++;
  }

  return No_of_Dist_elements;
}
// Time Complexity :- O(n^2)
// Aux Space :- O(1)


//______________________________________________________________________________

// Effecient Solution

// unordered_set overrides the same elements so copies of the int values are
// not transferred to unordered_set.

int E_Count_Distinct_Elements(vector<int> vector)
{
  unordered_set<int> container;

  for(int i=0; i<vector.size(); i++)
    container.insert(vector[i]);

  return container.size();
}
//Time Complexity :- O(n)
//Aux Space :- O(n)

//______________________________________________________________________________

// More Effecient Solution
// Same logic as effecient solution just done here in a line.

int E1_Count_Distinct_Elements(vector<int> vector)
{
  unordered_set<int> container(vector.begin(), vector.end());

  return container.size();
}
//Time Complexity :- Theta(n)
//Aux Space :- O(n)


int main()
{
  int length;

  cout<<"Length of Vector \n";
  cin>>length;
  vector<int> vector(length);

  cout<<"Enter the elements of the Vector \n";
  for(auto &i: vector)
    cin>>i;

  cout<<E1_Count_Distinct_Elements(vector);


  return 0;
}
