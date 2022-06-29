// What is a Majority Element?
// If an element appears more than n/2 times in an array then that element is a
// majority element. where n is no of elements in the array.

#include <bits/stdc++.h>
using namespace std;


int majorityelement(int a[], int n) //Naive Solution
{
  for(int i=0; i<n; i++)
  {
    int count = 1;
    for(int j=i+1; j<n; j++)
      if(a[i]==a[j])
        count++;
    if(count > n/2)
      return i;
  }
  return -1;
  // Time Complexity :- BigO(n^2)
  // Aux Space :- Theta(1)
}
//______________________________________________________________________________

// Moore's Voting Algorithm
// Concept of cancelling out each other's vote, if the element is same as the
// element at maj_index then increment count else decrement the count(cancelling
// out the count). If at any given point of time the count becomes zero reset
// the count to 1 and maj_index to current i.

// Approach: This is a two-step process.

// 1) This is Moore's Voting Algorithm
// The first step gives the element that maybe the majority element in the array.
// If there is a majority element in an array, then this step will definitely
// return majority element, otherwise, it will return candidate for majority
// element.

// 2)
// Check if the element obtained from the above step is majority element. This
// step is necessary as there might be no majority element.

int majorityelementE(int a[], int n)
{
  int maj_index = 0, count = 1;
  for(int i=1; i<n; i++)   // Moore's Algorithm
  {
    if(a[maj_index] == a[i])
      count++;
    else
      count--;
    if(count==0)
    {
      maj_index = i;
      count = 1;
    }
  }

  count = 0;
  for(int i=0; i<n; i++)
    if(a[maj_index] == a[i])
    count++;
  if(count > n/2)
    return maj_index;
  return -1;
  // Time Complexity :- BigO(n)
  // Aux Space :- Theta(1)
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
  cout<<majorityelementE(a, n);
  return 0;
}
