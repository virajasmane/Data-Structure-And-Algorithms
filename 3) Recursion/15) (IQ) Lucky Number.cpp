// Microsoft Question

// Take the set of integers
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,……
// First, delete every second number, we get following reduced set.
// 1, 3, 5, 7, 9, 11, 13, 15, 17, 19,…………
// Now, delete every third number, we get
// 1, 3, 7, 9, 13, 15, 19,….….
// Continue this process indefinitely……
// Any number that does NOT get deleted due to above process is called “lucky”.

// Input:
// N = 5
// Output: 0
// Explanation: 5 is not a lucky number
// as it gets deleted in the second
// iteration.

// Explanation :- https://youtu.be/eUiLzMPRamM

#include <bits/stdc++.h>
using namespace std;

int counter = 2;
bool luckyno(int n)
{
  if(n<counter)
    return true;
  if(n%counter==0)
    return false;

  n -= (n/counter);
  counter++;

  return isLucky(n);
}

int main()
{
  int n;
  cout<<"Enter no n \n";
  cin>>n;
  cout<<luckyno(n);
  return 0;
}

// why we are doing n - n/counter
// ANS:-
// Here n is the new position.
// so
// new_position = old_position - no_of_deleted_items
// no of deleted items before that position is n/counter
// for example;
// 1,2,3,4,5,6,7,...
// n=7;
// and counter is 2;
// new position => 7 - 7/2 = 4.
// so the new array formed is 1,3,5,7
// deleted items = >7/2=3
