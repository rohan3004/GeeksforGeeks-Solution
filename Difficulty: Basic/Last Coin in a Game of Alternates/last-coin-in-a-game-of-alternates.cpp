class Solution {
public:
    int coin(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        // Continue the game until exactly one coin remains
        while (left < right) {
            if (arr[left] >= arr[right]) {
                left++;  // Pick the left coin
            } else {
                right--; // Pick the right coin
            }
        }
        
        // Both left and right point to the same final remaining coin
        return arr[left];
    }
};