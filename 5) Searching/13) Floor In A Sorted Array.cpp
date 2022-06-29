// Given a sorted array arr[] of size N without duplicates, and given a value x.
// Floor of x is defined as the largest element K in arr[] such that K is smaller
// than or equal to x. Find the index of K(0-based indexing).

// Input:
// N = 7, x = 0
// arr[] = {1,2,8,10,11,12,19}
// Output: -1
// Explanation: No element less
// than 0 is found. So output
// is "-1".

// Input:
// N = 7, x = 5
// arr[] = {1,2,8,10,11,12,19}
// Output: 1
// Explanation: Largest Number less than 5 is
// 2 (i.e K = 2), whose index is 1(0-based
// indexing).

int findFloor(vector<long long> a, long long n, long long x)
    {
        int low = 0, high = n-1, res = -1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(a[mid] <= x)
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return (a[res] > x) ? -1 : res;
    }
