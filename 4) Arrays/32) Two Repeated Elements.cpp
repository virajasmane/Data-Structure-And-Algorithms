// You are given an array of N+2 integer elements. All elements of the array
// are in range 1 to N. Also, all elements occur once except two numbers which
// occur twice. Find the two repeating numbers.

// Input:
// N = 4
// array[] = {1,2,1,3,4,3}
// Output: 1 3
// Explanation: In the given array,
// 1 and 3 are repeated two times.

vector<int> twoRepeated (int a[], int n)
    {
        vector<int> result;
        int x = 0, y = 0;

        int XOR = a[0];
        for(int i=1; i<n+2; i++)
            XOR ^= a[i];
        for(int i=1; i<=n; i++)
            XOR ^= i;

        XOR = XOR & ~(XOR-1);

        for(int i=0; i<n+2; i++)
        {
            if(a[i] & XOR)
                x ^= a[i];
            else
                y ^= a[i];
        }
        for(int i=1; i<=n; i++)
        {
            if(i & XOR)
                x ^= i;
            else
                y ^= i;
        }
        result.push_back(y);
        result.push_back(x);
        return result;

    }
