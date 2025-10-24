#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  /**
   * @brief Determines if an array can be split into consecutive subsequences of length at least k.
   *
   * This problem can be solved using a greedy approach with hash maps.
   * The core idea is to iterate through the array and for each number,
   * decide whether to append it to an existing subsequence or start a new one.
   *
   * 1. We always prefer to **append** a number `x` to an existing subsequence
   * that ends at `x-1`. This is a greedy choice because it satisfies an
   * existing "need" for `x` without creating a new "demand" for `x+1, x+2, ...`.
   *
   * 2. If we cannot append `x` (because no subsequence ends at `x-1`),
   * we are **forced to start a new subsequence**.
   *
   * 3. When starting a new subsequence at `x`, it *must* have a length
   * of at least `k`. Therefore, we must immediately check if we have
   * enough copies of `x+1, x+2, ..., x+k-1` available to form this
   * new, valid subsequence.
   *
   * 4. If we are forced to start a new subsequence and cannot find the
   * required `k` numbers, we return `false`.
   *
   * We use two hash maps to track this:
   * - `freq`: `unordered_map<int, int>` stores the count of each number
   * that is still available to be used.
   * - `tails`: `unordered_map<int, int>` stores the number of subsequences
   * that are currently *ending* at a particular number. For example,
   * `tails[x] = 2` means two subsequences are waiting for `x+1`.
   *
   * Time Complexity: O(N), where N is the number of elements in `arr`.
   * - We iterate to build `freq` (O(N)).
   * - We iterate `arr` again (O(N)).
   * - Inside the loop, appending is O(1) on average.
   * - The "start new" operation involves a loop of `k` steps. However,
   * this operation "consumes" `k` elements from `freq`. Since there
   * are only N elements in total, this `k`-step loop can run at
   * most N/k times. The total amortized time for all "start new"
   * operations across the entire run is (N/k) * k = O(N).
   * - Therefore, the total time is O(N) + O(N) = O(N).
   *
   * Space Complexity: O(N) in the worst case to store `freq` and `tails`
   * if all elements are distinct.
   */
  bool isPossible(vector<int>& arr, int k) {
    // 1. Store the frequency of each number.
    unordered_map<int, int> freq;
    for (int x : arr) {
      freq[x]++;
    }

    // 2. `tails[x]` stores the number of subsequences ending at x.
    unordered_map<int, int> tails;

    // 3. Iterate through the array and try to place each number.
    for (int x : arr) {
      // If this number has already been used, skip it.
      if (freq[x] == 0) {
        continue;
      }

      // We are now using this number.
      freq[x]--;

      // **Option 1: Append to an existing subsequence**
      // Check if there is a subsequence ending at x-1.
      if (tails[x - 1] > 0) {
        // Yes, append this 'x' to that subsequence.
        tails[x - 1]--; // One less subsequence ends at x-1
        tails[x]++;     // One more subsequence now ends at x
      }
      // **Option 2: Start a new subsequence**
      // We can't append, so we must start a new subsequence.
      // This new subsequence MUST be of length k.
      else {
        // We must find k consecutive numbers (x, x+1, ..., x+k-1).
        // We already "used" x, so check for the next k-1 numbers.
        for (int i = 1; i < k; i++) {
          int nextNum = x + i;
          // If the required next number is not available, we fail.
          if (freq[nextNum] == 0) {
            return false;
          }
          // "Use" this number for the new subsequence.
          freq[nextNum]--;
        }
        // We successfully formed a k-length subsequence.
        // This new subsequence ends at x + k - 1.
        tails[x + k - 1]++;
      }
    }

    // If we processed the entire array without failing, it's possible.
    return true;
  }
};