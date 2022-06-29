// Microsoft Question

#include <bits/stdc++.h>
using namespace std;

void ToH(int n, char A, char B, char C)
{
  if(n==1)
  {
    cout<<"Move Disc 1 from "<<A<<" to "<<C<<" \n";
    return;
  }
  ToH(n-1, A, C, B);
  cout<<"Move Disc "<<n<<" from "<<A<<" to "<<C<<" \n";
  ToH(n-1, B, A, C);
  // No of Movements needed to make for a given n :- (pow(2,n) - 1)
}

int main()
{
  int n;
  cout<<"Enter a no n\n";
  cin>>n;
  ToH(n,'A','B','C');
	return 0;
}
