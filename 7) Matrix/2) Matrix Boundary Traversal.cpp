#include<bits\stdc++.h>
using namespace std;

void print(vector<vector<int>> &mat)
{
  if(mat.size() == 1) // If else condition for corner cases if there is only one row or one column.
  {
    for(int i=0; i<mat[0].size(); i++)
      cout<<mat[0][i]<<" ";
  }
  else if(mat[0].size() == 1)
  {
    for(int i=0; i<mat.size(); i++)
      cout<<mat[i][mat[0].size()-1]<<" ";
  }
  else
  {
    for(int i=0; i<mat[0].size(); i++)
      cout<<mat[0][i]<<" ";
    for(int i=1; i<mat.size(); i++)
      cout<<mat[i][mat[0].size()-1]<<" ";
    for(int i=mat[0].size()-2; i>=0; i--)
      cout<<mat[mat.size()-1][i]<<" ";
    for(int i=mat.size()-2; i>0; i--)
      cout<<mat[i][0]<<" ";
  }
  // Time Complexity :- Theta( row + column)
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
