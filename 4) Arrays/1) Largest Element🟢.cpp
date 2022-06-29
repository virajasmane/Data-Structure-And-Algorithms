#include <bits/stdc++.h>
using namespace std;


int largestelement(int a[], int N)
{
  int temp=a[0];  // temp = 0    If asked to return the index
  for(int i=1; i<N; i++)
    if(temp<a[i]) // a[temp] < a[i]
      temp = a[i];// temp = i
  return temp;
  // Time Complexity :- Theta( n )
}

int main()
{
  int N;
  cout<<"Enter N \n";
  cin>>N;
  int a[N];
  cout<<"Enter the elements of array\n";
  for(int i=0;i<N;i++)
    cin>>a[i];
  cout<<"Largest Element is "<<largestelement(a, N);
  return 0;
}
