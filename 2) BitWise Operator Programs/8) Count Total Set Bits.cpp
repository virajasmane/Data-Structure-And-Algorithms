#include <bits/stdc++.h>
using namespace std;

//Explaination- https://www.youtube.com/watch?v=g6OxU-hRGtY&ab_channel=Pepcoding
// n: input to count the number of set bits
//Function to return sum of count of set bits in the integers from 1 to n.
int countSetBits(int n)
{
    if(n==0)
        return 0;
    int x = log2(n);
    int x1 = x * 1<<(x-1);
    int x2 = n - (1<<x) +1;
    int x3 = n - (1<<x);
    int ans = x1 + x2 + countSetBits(x3);
    return ans;
}

int main()
{
  int n;
  cout<<"Enter a number\n";
  cin>>n;
  cout<<countSetBits(n);
	return 0;
}
