// MICROSOFT QUESTION

#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(int N) //Naive solution
{
    int count=0,temp=0;
    while(N>0)
    {
        if(N%2==1)
            count++;
        else
        {
            if(count>temp)
                temp = count;
            count=0;
        }
        N /= 2;
    }
    if(temp<count)
        return count;
    else
        return temp;
    // Time Complexity :- Log2(N)
}
//______________________________________________________________________________

// The idea is based on the concept that if we AND a bit sequence with a shifted
// version of itself, we're effectively removing the trailing 1 from every
// sequence of consecutive 1's.
// So the operation x = (x & (x << 1)) reduces length of every sequence of 1s by
// one in binary representation of x. If we keep doing this operation in a loop,
// we end up with x = 0. The number of iterations required to reach 0 is actually
// length of the longest consecutive sequence of 1s.


int maxConsecutiveOnesB(int N)
    {

        int count=0;
        while(N!=0)
        {
            N = N & (N<<1);
            count++;
        }
        return count;
        // Time Complexity :- Theta( No of  times consecutive 1's appear )
    }


int main()
{
  int n;
  cout<<"Enter a number\n";
  cin>>n;
  cout<<maxConsecutiveOnes(n);
	return 0;
}
