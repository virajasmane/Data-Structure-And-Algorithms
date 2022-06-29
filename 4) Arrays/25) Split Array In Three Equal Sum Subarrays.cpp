
#include <bits/stdc++.h>
using namespace std;

int dividesubarray(int a[], int n)
{
  int sum = 0;
  for(int i=0; i<n; i++)
    sum += a[i];
  if(sum%3 != 0)
    return 0;
  int s1 = sum/3;
  int s2 = 2*s1;
  int curr_sum = 0, ind1 = -1, ind2 = -1;
  for(int i=0; i<n; i++)
  {
    curr_sum += a[i];
    if(curr_sum == s1 && ind1 == -1)
      ind1 = i;
    else if(curr_sum == s2 && ind1 != -1)
    {
      ind2 = i;
      break;
    }
  }
  if(ind1 != -1 && ind2 != -1)
  {
    cout<<ind1<<" "<<ind2<<"\n";
  }
  return 0;
  // Time Complexity :- BigO(n)
  // Aux Complexity :- Theta(1)
}


int main()
{
  int n;
  cout<<"Enter N \n";
  cin>>n;
  int a[n];
  cout<<"Enter the elements of array\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<dividesubarray(a, n);
  return 0;
}
