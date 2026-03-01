class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int count = 0; // Index of the next non-zero element
        
        for (int i = 0; i < arr.size(); i++) {
            // If the current element is non-zero
            if (arr[i] != 0) {
                // Swap it with the element at 'count' index
                swap(arr[i], arr[count]);
                // Move the count pointer forward
                count++;
            }
        }
    }
};