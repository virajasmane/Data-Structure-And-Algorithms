// n = 99999
// Output: 9
// Explanation: Sum of digits of 99999 is 45
// which is not a single digit number, hence
// sum of digit of 45 is 9 which is a single
// digit number.

#include <bits/stdc++.h>
using namespace std;

int digitalRoot(int n)
    {
        return n<10 ? n : digitalRoot(n%10 + n/10);
    }

    int main()
    {
      int n;
      cout<<"Enter no n \n";
      cin>>n;
      cout<<digitalRoot(n);
    	return 0;
    }
