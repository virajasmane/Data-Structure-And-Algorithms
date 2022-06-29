#include<bits\stdc++.h>
using namespace std;

void print(vector<vector<int>> &mat)
{
  int top = 0, left = 0, right = mat[0].size()-1, bottom = mat.size()-1;
  while(top <= bottom && left <= right)
  {
    for(int i=left; i<=right; i++) //Print top row
      cout<<mat[top][i]<<" ";
    top++;

    for(int i=top; i<=bottom; i++) //print right column
      cout<<mat[i][right]<<" ";
    right--;

    if(top <= bottom) //print bottom row in reverse order.
    {
      for(int i=right; i>=left; i--)
        cout<<mat[bottom][i]<<" ";
      bottom--;
    }

    if(left <= right) //print left column in reverse order.
    {
      for(int i=bottom; i>=top; i--)
        cout<<mat[i][left]<<" ";
      left++;
    }
  }

  // Time Complexity :- Theta( Row * column)
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
