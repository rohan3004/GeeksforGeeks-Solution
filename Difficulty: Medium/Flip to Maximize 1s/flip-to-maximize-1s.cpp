class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int originalOnes = 0;
        int maxGain = 0;      // Max extra 1s we can get from a flip
        int currentGain = 0;  // Running total of extra 1s

        for (int i = 0; i < arr.size(); i++) {
            // Count original 1s and calculate the gain/loss for the current element
            if (arr[i] == 1) {
                originalOnes++;
                currentGain -= 1; // Flipping a 1 loses us a 1
            } else {
                currentGain += 1; // Flipping a 0 gains us a 1
            }

            // If the current contiguous subarray has a negative net gain, 
            // it's better to start a new subarray.
            if (currentGain < 0) {
                currentGain = 0;
            }

            // Update the maximum gain found so far
            if (currentGain > maxGain) {
                maxGain = currentGain;
            }
        }

        // Total 1s is the baseline 1s plus the best net gain we found
        return originalOnes + maxGain;
    }
};