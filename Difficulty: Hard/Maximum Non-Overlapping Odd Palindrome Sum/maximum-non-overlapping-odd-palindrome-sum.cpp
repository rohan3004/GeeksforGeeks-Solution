#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    // Computes radii of all odd-length palindromes using Manacher's algorithm.
    // d1[i] = radius of the palindrome centered at s[i].
    // The palindrome is s[i-d1[i]...i+d1[i]], and its length is 2*d1[i]+1.
    std::vector<int> manacher_odd(const std::string& s) {
        int n = s.length();
        std::vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : std::min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k - 1;
            if (i + d1[i] > r) {
                l = i - d1[i];
                r = i + d1[i];
            }
        }
        return d1;
    }

    // Calculates the max length of an odd-length palindrome starting at each index.
    std::vector<int> calculate_max_len_starts_at(int n, const std::vector<int>& d1) {
        // Sweep-line approach
        std::vector<std::vector<int>> add_events(n), remove_events(n + 1);
        for (int i = 0; i < n; ++i) {
            int radius = d1[i];
            int start_idx = i - radius;
            int end_idx = i;
            add_events[start_idx].push_back(2 * i + 1);
            remove_events[end_idx + 1].push_back(2 * i + 1);
        }

        std::multiset<int> active_values;
        std::vector<int> max_c(n);

        for (int i = 0; i < n; ++i) {
            for (int val : add_events[i]) {
                active_values.insert(val);
            }
            for (int val : remove_events[i]) {
                active_values.erase(active_values.find(val));
            }
            if (!active_values.empty()) {
                max_c[i] = *active_values.rbegin();
            } else {
                max_c[i] = 0;
            }
        }

        std::vector<int> max_len_at_start(n);
        for (int i = 0; i < n; ++i) {
            if (max_c[i] > 0) {
                // length = max(-2j + (2c+1)) = -2j + max(2c+1) = -2*i + max_c[i]
                max_len_at_start[i] = max_c[i] - 2 * i;
            } else {
                max_len_at_start[i] = 1; 
            }
            max_len_at_start[i] = std::max(1, max_len_at_start[i]);
        }
        return max_len_at_start;
    }

    int maxSum(std::string &s) {
        int n = s.length();
        if (n < 2) {
            return 0;
        }

        // Forward pass
        std::vector<int> d1_s = manacher_odd(s);
        std::vector<int> max_len_starts = calculate_max_len_starts_at(n, d1_s);
        
        // Backward pass (by reversing the string)
        std::string s_rev = s;
        std::reverse(s_rev.begin(), s_rev.end());
        std::vector<int> d1_rev = manacher_odd(s_rev);
        std::vector<int> max_len_starts_rev = calculate_max_len_starts_at(n, d1_rev);

        std::vector<int> max_len_ends(n);
        for(int i = 0; i < n; ++i) {
            max_len_ends[i] = max_len_starts_rev[n - 1 - i];
        }

        // `pref[i]` = max palindrome length in s[0...i]
        std::vector<int> pref(n, 0);
        pref[0] = max_len_ends[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = std::max(pref[i - 1], max_len_ends[i]);
        }

        // `suff[i]` = max palindrome length in s[i...n-1]
        std::vector<int> suff(n, 0);
        suff[n - 1] = max_len_starts[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suff[i] = std::max(suff[i + 1], max_len_starts[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            // A character is a palindrome of length 1, so pref/suff are always > 0.
            ans = std::max(ans, pref[i] + suff[i + 1]);
        }

        return ans;
    }
};