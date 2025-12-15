class Solution {
  public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        long long totalOdd = 0, totalEven = 0;

        // 1. Calculate total sums for odd and even indices
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) totalEven += arr[i];
            else totalOdd += arr[i];
        }

        long long currOdd = 0, currEven = 0;
        int count = 0;

        // 2. Iterate through each element to simulate removal
        for (int i = 0; i < n; ++i) {
            // Calculate sums of the suffix (elements AFTER i)
            // Note: We subtract current prefix sums. We also subtract arr[i] 
            // from the respective total to ensure strictly suffix sums.
            long long suffixOdd = totalOdd - currOdd;
            long long suffixEven = totalEven - currEven;

            if (i % 2 == 0) suffixEven -= arr[i];
            else suffixOdd -= arr[i];

            // 3. Calculate new sums after removal:
            // New Even Sum = Prefix Evens + Suffix Odds (shifted)
            // New Odd Sum = Prefix Odds + Suffix Evens (shifted)
            if (currEven + suffixOdd == currOdd + suffixEven) {
                count++;
            }

            // Update prefix sums for the next iteration
            if (i % 2 == 0) currEven += arr[i];
            else currOdd += arr[i];
        }

        return count;
    }
};