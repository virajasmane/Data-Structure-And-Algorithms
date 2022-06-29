#include<bits/stdc++.h>
using namespace std;

void CountingSort(vector<int> &a, int n, int exp)
{
  vector<int> count(10, 0);

  for(int i=0; i<n; i++)
    count[ (a[i]/exp)%10 ]++;

  for(int i=1; i<10; i++)
      count[i] += count[i-1];

  vector<int> output(n);
  for(int i=n-1; i>=0; i--) // here we go from n-1 to 0 not 0 to n-1 to maintain stability.
  {
    output[ count[ (a[i]/exp)%10 ] - 1 ] = a[i]; // here we're transfering the whole object back and forth not just i so it wont have any error for any data type.
    count[ (a[i]/exp)%10 ]--;
  }

  for(int i=0; i<n; i++)
    a[i] = output[i];
}

void RadixSort(vector<int> &a, int n)
{
  int maximum_element = *max_element(a.begin(), a.end());

  for(int exp=1; maximum_element/exp>0; exp *= 10) // This loop will run for last digits of element then second last then third last and so on untill it becomes zero
    CountingSort(a, n, exp);
}

// Time Complexity :- Theta( d * (n + b) ) where d = digits in max_element of a
// Aux Space :- Theta(n+b)                       b = base in this case 10

int main()
{
  int n;
  cout<<"Enter the no of elements of the array\n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements of the array \n";
  for(auto &i: a)
    cin>>i;
  RadixSort(a, n);
  for(auto &i: a)
    cout<<i<<" ";
  return 0;
}
