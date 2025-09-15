#include <string>

class Solution {
 public:
  bool stringStack(string &pat, string &tar) {
    // Initialize pointers to the end of each string.
    int pat_ptr = pat.length() - 1;
    int tar_ptr = tar.length() - 1;

    // Process the pattern string from right to left.
    while (pat_ptr >= 0) {
      // If the current characters match, we greedily use pat[pat_ptr] for tar[tar_ptr].
      // This corresponds to a successful "Append" operation.
      // We then move to the previous character in both strings.
      if (tar_ptr >= 0 && pat[pat_ptr] == tar[tar_ptr]) {
        pat_ptr--;
        tar_ptr--;
      } else {
        // If characters don't match, or if tar is fully matched,
        // pat[pat_ptr]'s operation must be "skipped" or canceled out.
        // A pair of operations (like one Append, one Delete) can have a net-zero effect.
        // This consumes two characters from the pattern. So, we skip pat[pat_ptr] and pat[pat_ptr-1].
        pat_ptr -= 2;
      }
    }

    // If we've matched all characters of tar, tar_ptr will be less than 0.
    return tar_ptr < 0;
  }
};