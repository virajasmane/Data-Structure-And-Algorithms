#include <bits/stdc++.h>
using namespace std;

// Eg
// I/P :- {10, 10, 10, 12, 12, 12, 15, 20}
// O/P :- 10 3
//        12 3
//        15 1
//        20 1

// I/P :- {10, 10, 10, 10}
// O/P :- 10 4

// Naive Solution
void Frequency_of_Elements(vector<int> vector)
{
  for(int i=0; i<vector.size(); i++)
  {
    bool isEqual = false;
    for(int j=0; j<i; j++)
    {
      if(vector[j] == vector[i])
      {
        isEqual = true;
        break;
      }
    }
    if(isEqual == true)
      continue;
    int result = 1;
    for(int j=i+1; j<vector.size(); j++)
    {
      if(vector[i] == vector[j])
        result++;
    }
    cout<<vector[i]<<": "<<result<<endl;
  }
}
// Time Complexity :- O(n^2)
// Aux Space :- O(1)
//______________________________________________________________________________

// Effecient Solution

void E_Frequency_of_Elements(vector<int> vector)
{
  unordered_map<int, int> container;
  for(int i=0; i<vector.size(); i++)
    container[vector[i]]++; // Here if the key entered is not already
                            // present then it is added to unordered_map
                            // and value is set to default (0) and if key is
                            // already present then it increments the value.
  for(auto iterator: container)
    cout<<iterator.first<<" "<<iterator.second<<endl;
}
// Time Complexity :- O(n)
// Aux Space :- O(n)



int main()
{
  int length;

  cout<<"Length of Vector \n";
  cin>>length;
  vector<int> vector(length);

  cout<<"Enter the elements of the Vector \n";
  for(auto &i: vector)
    cin>>i;

  E_Frequency_of_Elements(vector);


  return 0;
}
