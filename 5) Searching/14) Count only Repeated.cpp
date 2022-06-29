//https://practice.geeksforgeeks.org/problems/count-only-repeated2047/1/?track=DSASP-Searching&batchId=154#

// Given an array arr[] of N positive integers, where elements are consecutive
// (sorted). Also, there is a single element which is repeating X (any variable)
// number of times. Now, the task is to find the element which is repeated and
// number of times it is repeated.
// Note: If there's no repeating element, Return {-1,-1}.

// Input:
// N = 5
// arr[] = {1,2,3,3,4}
// Output: 3 2
// Explanation: In the given array, 3 is
// occuring two times.

// Input:
// N = 5
// arr[] = {2,3,4,5,5}
// Output: 5 2
// Explanation: In the given array, 5 is
// occuring two times.

// Easy Explanation:
// Since array elements are consecutive(sorted), that means, we need to discard
// one half in our algorithm, so we will be definitely using a binary search
// based approach, to solve problem in Log(N) time
//
// To understand how many times elements is repeated, this is basic maths:
// Say, you were given consecutive distinct elements, then , those elements
// would form an A.P, where the last element can be computed using formula
// a + (n-1)*d, in out case it would be arr[n-1] = arr[0] + (n-1);
// Given that we have consecutive distinct elements
//
// now if an element is repeating K no. of times , then last element will
// decrease by (K-1), so
// arr[n-1] = arr[0] + (n-1) - (k-1) which will give,
// arr[n-1] = arr[0] + (n - k);
//
// So K can be computed as in O(1) time:
// K = arr[0] + n - arr[n-1];
//
// To Find the repeating element:
//
// Say, you were given consecutive distinct elements, then the mid element would
// be arr[mid] = arr[0] + mid;
//
// if arr[mid] < arr[0] + mid then repeating element will definitely be on the
// left half else it will be on the right half.

pair<int, int> findRepeating(int *a, int n)
    {
        pair<int,int> result;
        result.first = -1;
        result.second = -1;

        if(a[0] + n - a[n-1] == 1) // Base Case
            return result;

        result.second = a[0] + n - a[n-1];

        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid = (low+high)/2;

            if(a[mid] < a[0] + mid)
            {
                high = mid - 1;
                if(a[mid] == a[mid-1] || a[mid] == a[mid+1])
                {
                    result.first = a[mid];
                    return result;
                }
            }
            else
            {
               low = mid + 1;
               if(a[mid] == a[mid-1] || a[mid] == a[mid+1])
                {
                    result.first = a[mid];
                    return result;
                }
            }
        }

    }
