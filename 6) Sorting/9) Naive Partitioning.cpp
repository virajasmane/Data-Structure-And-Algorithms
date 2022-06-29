// Naive partitioning is stable and takes O(n) time and O(n) extra space.

#include<bits/stdc++.h>
using namespace std;


int NaivePartition(vector<int> a, int low, int high, int pivot)
{
  vector<int> temp(high-low+1); //Create temp array
  int index = 0;

  for(int i=low; i<=high; i++) // transfer elements smaller than pivot in temp
    if(a[i] < a[pivot])
    {
      temp[index] = a[i];
      index++;
    }

  for(int i=low; i<=high; i++) // transfer elements equal to pivot in temp. We do this seperately and not in the above for loop to maintain stability
    if(a[i] == a[pivot])
    {
      temp[index] = a[i];
      index++;
    }

  int result = low + index - 1; // index of Last occerence of pivot is stored in result which is our answer.

  for(int i=low; i<=high; i++) // transfer elements greater than pivot in temp
    if(a[pivot] < a[i])
    {
      temp[index] = a[i];
      index++;
    }

  for(int i=low; i<=high; i++) // copy to Original array
    a[i] = temp[i-low];

  return result;

}
// Time Complexity :- O(n)
// Aux Space :- Theta(n)

int main()
{
  int n, pivot;
  cout<<"Enter the no of elements of the array\n";
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the elements of the array \n";
  for(auto &i: a)
    cin>>i;
  cout<<"Enter the index of the pivot element\n";
  cin>>pivot;
  cout<<NaivePartition(a, 0, n-1, pivot);
  return 0;
}
