//Link :- https://practice.geeksforgeeks.org/tracks/DSASP-Sorting/?batchId=154#

#include<bits/stdc++.h>
using namespace std;

int MaxGuests(vector<int> arrival, vector<int> departure, int n)
{
  sort(arrival.begin(), arrival.end());
  sort(departure.begin(), departure.end());
  int i = 1, j = 0, curr_guests = 1, max_guests = 1;
  while(i < n && j < n)
  {
    if(arrival[i] <= departure[j])
    {
      curr_guests++;
      i++;
    }
    else if(departure[j] <= arrival[i])
    {
      curr_guests--;
      j++;
    }
    max_guests = max(max_guests, curr_guests);
  }
  return max_guests;
}
// Time Complexity :- O(NlogN)
// Space Complexity :- O(1)

int main()
{
  int n;
  cout<<"Enter the no of elements of the array\n";
  cin>>n;
  vector<int> arrival(n);
  vector<int> departure(n);
  cout<<"Enter the arrival time \n";
  for(auto &var: arrival)
    cin>>var;
  cout<<"Enter the departure time \n";
  for(auto &var: departure)
    cin>>var;
  cout<<MaxGuests(arrival, departure, n);

  return 0;
}
