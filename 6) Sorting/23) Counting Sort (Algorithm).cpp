#include<bits/stdc++.h>
using namespace std;



void CountingSort(vector<int> &a, int n, int k) //Naive Solution
{                              // Will only work for integers not pairs etc,
  int j = 0, temp[k] = {0};    // pairs in the sense a[] = { (5,"ram"), (3,"sam") }
  for(int i=0; i<n; i++)       // because at ## step (14th line) we're transfering i into whole array object which is not possible beacuse its data type not plain array
    temp[a[i]]++;
  for(int i=0; i<k; i++)
    while(temp[i] && j<n)
    {
      a[j] = i; /*  ##  */
      temp[i]--;
      j++;
    }
}
// Time Complexity :- O(n+k)
// Space Complexity :- O(k)

//______________________________________________________________________________

// General purpose Sorting Algorithm

void CountingSortG(vector<int> &a, int n, int k)
{
  vector<int> count(k, 0);

  for(int i=0; i<n; i++)
    count[a[i]]++;

  for(int i=1; i<k; i++)
      count[i] += count[i-1];

  vector<int> output(n);
  for(int i=n-1; i>=0; i--) // here we go from n-1 to 0 not 0 to n-1 to maintain stability.
  {
    output[ count[ a[i] ] - 1 ] = a[i]; // here we're transfering the whole object back and forth not just i so it wont have any error for any data type.
    count[a[i]]--;
  }

  for(int i=0; i<n; i++)
    a[i] = output[i];
}
// Time Complexity :- Theta(n+k)
// Space Complexity :- Theta(n+k)

int main()
{
  int n, k;
  cout<<"Enter k \n";
  cin>>k;
  cout<<"Enter the no of elements of the array\n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements of the array \n";
  for(auto &i: a)
    cin>>i;
  CountingSortG(a, n, k);
  for(auto &i: a)
    cout<<i<<" ";
  return 0;
}
