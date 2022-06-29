// You are given two numbers A and B. The task is to count the number of bits
// needed to be flipped to convert A to B

#include <bits/stdc++.h>
using namespace std;

int countBitsFlip(int a, int b)
    {
        int n = a^b;
        int res = 0;
        while(n>0)
        {
            n &= (n-1);
            res++;
        }
        return res;
    }

int main()
{
  int a,b;
  cout<<"Enter a and b\n";
  cin>>a>>b;
  cout<<countBitsFlip(a,b);
	return 0;
}
