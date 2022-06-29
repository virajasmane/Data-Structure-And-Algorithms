#include<bits\stdc++.h>
using namespace std;

//Naive solution is to traverse all mat elements one by one.
//Below is the effecient solution.

void print(vector<vector<int>> &mat, int x)
{
  int row = 0, column = mat.size()-1;
  while(row < mat.size() && column >= 0)
  {
    if(mat[row][column] == x)
    {
      cout<<"Found At ("<<row<<", "<<column<<")";
      return;
    }
    else if(mat[row][column] > x)
      column--;
    else
      row++;
  }
  cout<<"Not Found";

  // Time Complexity :- Theta(row + column)
}

int main()
{
  int x = 51;
  vector<vector<int>> mat = {{10, 20, 30, 40},
    			                   {15, 25, 35, 45},
    			                   {27, 29, 35, 45},
    			                   {32, 33, 39, 50}};
  print(mat, x);

  return 0;
}
