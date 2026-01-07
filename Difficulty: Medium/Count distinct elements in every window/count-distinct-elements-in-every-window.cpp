class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> result;
        unordered_map<int, int> freqMap;

        // 1. Process the first window
        for (int i = 0; i < k; i++) {
            freqMap[arr[i]]++;
        }
        result.push_back(freqMap.size());

        // 2. Slide the window from index k to n-1
        for (int i = k; i < n; i++) {
            // Remove the element that is sliding out of the window
            int outElement = arr[i - k];
            freqMap[outElement]--;
            
            // If the count becomes 0, remove it from the map to keep size accurate
            if (freqMap[outElement] == 0) {
                freqMap.erase(outElement);
            }

            // Add the new element sliding into the window
            int inElement = arr[i];
            freqMap[inElement]++;

            // The number of unique keys in the map is the distinct count
            result.push_back(freqMap.size());
        }

        return result;
    }
};