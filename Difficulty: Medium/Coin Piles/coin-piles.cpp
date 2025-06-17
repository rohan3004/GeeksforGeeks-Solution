#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return 0;

        // Sort piles
        sort(arr.begin(), arr.end());

        // Build prefix sums of arr
        // ps[i] = sum of arr[0..i-1], so ps[0]=0, ps[n]=sum of all
        vector<long long> ps(n+1, 0);
        for (int i = 0; i < n; i++) {
            ps[i+1] = ps[i] + arr[i];
        }

        long long ans = LLONG_MAX;
        // We'll also consider low = 0 as a candidate
        // so treat it specially before iterating arr[]
        {
            int idxR = upper_bound(arr.begin(), arr.end(), k) - arr.begin();
            // cost to bring all piles > k down to k
            long long sumUpper = ps[n] - ps[idxR];
            long long costUpper = sumUpper - 1LL*(n - idxR)*(k);
            ans = min(ans, costUpper);
        }

        // Now for each unique arr[j] as the "low" end of our window
        for (int j = 0; j < n; j++) {
            // skip duplicates
            if (j > 0 && arr[j] == arr[j-1]) continue;

            long long low = arr[j];
            // find how many piles < low  (i.e. indices [0..j-1])
            long long costLower = ps[j];  
                // we have to remove all coins from those piles

            // find first index > low+k
            long long threshold = low + k;
            int idxR = upper_bound(arr.begin(), arr.end(), threshold) - arr.begin();
            // piles in [idxR..n-1] are > low+k
            long long sumAbove = ps[n] - ps[idxR];
            long long countAbove = n - idxR;
            long long costUpper = sumAbove - countAbove * threshold;
                // for each such pile we remove (arr[i] - threshold)

            ans = min(ans, costLower + costUpper);
        }

        return (int)ans;
    }
};
