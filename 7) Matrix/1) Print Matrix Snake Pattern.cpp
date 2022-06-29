#include<bits\stdc++.h>
using namespace std;

void print(vector<vector<int>> &mat)
{
  for(int i=0; i<mat.size(); i++)
  {
    if(i%2 == 0)
      for(int j=0; j<mat[i].size(); j++)
        cout<<mat[i][j]<<" ";
    else
      for(int j=mat[i].size()-1; j>=0; j--)
        cout<<mat[i][j]<<" ";
  }

  //Time Complexity :- Theta( mat.size() * mat[i].size() )
}

int main()
{
  vector<vector<int>> mat = { {1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12},
                              {13, 14, 15, 16} };
  print(mat);

  return 0;
}
