class Solution {
public:
int maxOnes(vector<int>& arr, int k) {
int left = 0; // The left pointer of our sliding window
 int zero_count = 0; // To count the number of zeros in the current window
 int max_length = 0; // To store the maximum length found so far

// 'right' is the right pointer of the window, which expands the window
for (int right = 0; right < arr.size(); ++right) {
// If the element at the right pointer is a zero, increment our count
if (arr[right] == 0) {
zero_count++;
 }

 // If the number of zeros in our window exceeds 'k', we need to shrink it
while (zero_count > k) {
// If the element at the left pointer is a zero, decrement the count
// as it's about to be removed from the window.
 if (arr[left] == 0) {
zero_count--;
}
// Move the left pointer to the right to shrink the window
left++;
}

// After ensuring the window is valid (zeros <= k), calculate its length
// and update the maximum length if this one is larger.
max_length = max(max_length, right - left + 1);
}

return max_length;
}
};