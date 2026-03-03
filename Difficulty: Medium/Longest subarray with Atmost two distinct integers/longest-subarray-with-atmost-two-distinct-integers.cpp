class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        if (n <= 2) return n;

        unordered_map<int, int> freq;
        int left = 0, maxLen = 0;

        for (int right = 0; right < n; ++right) {
            // Add current element to the window
            freq[arr[right]]++;

            // If we have more than 2 distinct elements, shrink from the left
            while (freq.size() > 2) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                left++;
            }

            // Calculate the length of the current valid window
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};