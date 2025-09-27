class Solution {
 public:
  int kBitFlips(vector<int>& arr, int k) {
    int n = arr.size();
    int flips = 0;
    // This variable tracks the current flip state. 
    // 0 means an even number of active flips cover this index.
    // 1 means an odd number of active flips cover this index.
    int current_flip_state = 0;

    for (int i = 0; i < n; ++i) {
      // If we are at least k elements in, a flip that started at `i-k`
      // is now out of range and its effect should be removed.
      if (i >= k) {
        // We marked the start of a flip by adding 2.
        // If arr[i-k] > 1, a flip was initiated there.
        if (arr[i - k] > 1) {
          current_flip_state ^= 1; // Toggle the state
        }
      }

      // Check if the current element needs to be flipped.
      // Its effective value is `arr[i] ^ current_flip_state`.
      // If the effective value is 0, we must flip.
      // This is equivalent to `arr[i] == current_flip_state`.
      if (arr[i] == current_flip_state) {
        // If a flip is needed but we don't have enough elements left
        // for a full k-length subarray, it's impossible.
        if (i + k > n) {
          return -1;
        }

        // Perform the flip
        flips++;
        current_flip_state ^= 1; // The new flip affects the state
        arr[i] += 2; // Mark that a flip started here
      }
    }
    return flips;
  }
};