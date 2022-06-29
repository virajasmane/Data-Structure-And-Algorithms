// Amazon, Flipkart, Microsoft, Walmart, JP Morgan, Morgan Stanley Question
//IMPORTANT QUESTION

#include <bits/stdc++.h>
using namespace std;

void lettercomb(int a[], int N, vector<string> &res, string nums[], int index, string s)
{
    if(index == N)
    {
        res.push_back(s);
        return;
    }
    string val = nums[a[index]];
    for(int j=0; j<val.length(); j++)
        lettercomb(a, N, res, nums, index+1, s+val[j]);
}

vector<string> possibleWords(int a[], int N)
{
    vector<string> res;
    if(N==0)
        return res;
    string nums[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    lettercomb(a, N, res, nums, 0, "");
    return res;
}

int main()
{
  int N;
  cout<<"Enter N\n";
  cin>>N;
  int a[N];
  cout<<"Enter the elements of array\n";
  for(int i=0;i<N;i++)
    cin>>a[i];
  vector<string> resa = possibleWords(a, N);
  for(auto i: resa)
    cout<<i<<" ";
  return 0;
}
