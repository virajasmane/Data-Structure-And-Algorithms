#include <bits/stdc++.h>
using namespace std;

// ONE ODD NUMBER

void findOdd(int arr[], int n)//naive solution
{

  for(int i=0; i<n; i++)
  {
    int count = 0;
    for(int j=0; j<n; j++)
      if(arr[j]==arr[i])
        count++;
    if(count%2!=0)
    {
      cout<<arr[i];
      break;
    }
  }
  // Time Complexity :- Theta( square(n) )
}
//______________________________________________________________________________

// Optimized Solution
// Will use XOR operation, some intresting properties about XOR operators
// x ^ 0 = x
// x ^ x = 0
// x ^ (y ^ z) = (x ^ y) ^ z
// x ^ y = y ^ x
// Will XOR all the elements of the array and the no occuring odd no of times,
// will remain

void findOddX(int arr[], int n)
{
  int XOR = 0;
  for(int i=0; i<n; i++)
    XOR = XOR ^ arr[i];
  cout<<XOR;
  // Time Complxity :- Theta( n )
}
//______________________________________________________________________________

// Variation Question :-
/* Given an array of n numbers that has values from range 1 to n+1, every no
   appears exactly once. So one no is missing, find that numbers
   eg arr = {1,4,3}
      O/P = 2 */

void findOddV(int arr[], int n)
{
  int XOR = 0  ,XOR1 = 0;
  for(int i=1; i<=n+1; i++)
    XOR = XOR ^ i;
  for(int i=0; i<n; i++)
    XOR1 = XOR1 ^ arr[i];
  cout<<(XOR^XOR1);
  // If you want detailed explanation of this solution watch One odd occuring
  // video in bitwise operators section.
}
//______________________________________________________________________________
//______________________________________________________________________________

// TWO ODD NUMBERS

void findOdd2(int arr[], int n) // Naive Solution
{
  for(int i=0; i<n; i++)
  {
    int count = 0;
    for(int j=0; j<n; j++)
    if(arr[i]==arr[j])
      count++;
    if(count%2!=0)
      cout<<"ANS = "<<arr[i]<<endl;
  }
  // Time Complexity :- Theta( square(n) )
}

//______________________________________________________________________________

// Optimized Solution
// Will use XOR operation, some intresting properties about XOR operators
// x ^ 0 = x
// x ^ x = 0
// x ^ (y ^ z) = (x ^ y) ^ z
// x ^ y = y ^ x
/* Will XOR all the elements of the array and the XOR of nos occuring odd no
   of times, will remain. */

void findOdd2X(int arr[], int n)
{
  int XOR=0, res1=0, res2=0;
  for(int i=0; i<n; i++)
    XOR = XOR ^ arr[i];
  int x = XOR & ~(XOR-1);// will return a no with only Rightmost set bit of XOR
                        // set.
  for(int i=0; i<n; i++)
  {
    if((arr[i]&x) != 0)
      res1 = res1 ^ arr[i];//----
    else                   //   |---> These two to seperate nos into two groups
      res2 = res2 ^ arr[i];//----
  }
  cout<<"ANS = "<<res1<<"\t"<<res2;
  //Time Complexity :- Theta(n)
}


int main()
{
  int n;
  cout<<"Enter the no of elements\n";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements of an array\n";
  for(int i=0; i<n; i++)
    cin>>arr[i];
  findOdd2X(arr,n);

	return 0;
}
