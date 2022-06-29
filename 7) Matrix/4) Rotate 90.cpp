#include<bits\stdc++.h>
using namespace std;

void print(vector<vector<int>> &mat)
{

  for(int i=0; i<mat.size(); i++)
    for(int j=i+1; j<mat[i].size(); j++)
      swap(mat[i][j], mat[j][i]);
  for(int i=0; i<mat.size()/2; i++)
    swap(mat[i], mat[mat.size()-1-i]);
  for(int i=0; i<mat.size(); i++)
    for(int j=0; j<mat[i].size(); j++)
      cout<<mat[i][j]<<" ";

  // Time Complexity :-
}

int main()
{
  vector<vector<int>> mat = { { 1,  2,  3,  4  },
                              { 5,  6,  7,  8  },
                              { 9,  10, 11, 12 },
                              { 13, 14, 15, 16 } };
  print(mat);

  return 0;
}
