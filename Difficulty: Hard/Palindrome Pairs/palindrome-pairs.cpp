#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to check if a string is a palindrome
    bool isPalindrome(const string& s) {
        int left = 0, right = (int)s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++; 
            right--;
        }
        return true;
    }

public:
    bool palindromePair(vector<string>& arr) {
        unordered_map<string, int> freq;
        
        // Populate the frequency map
        for (const string& s : arr) {
            freq[s]++;
        }

        // Check each string to see if its required counterpart exists
        for (const string& s : arr) {
            int len = s.length();
            
            // Try all possible splits of the string into left and right substrings
            for (int i = 0; i <= len; ++i) {
                string left = s.substr(0, i);
                string right = s.substr(i);

                // If the left prefix is a palindrome, look for the reversed right suffix
                if (isPalindrome(left)) {
                    string target = right;
                    reverse(target.begin(), target.end());
                    
                    if (freq.find(target) != freq.end()) {
                        // Ensure we don't map a string to itself unless there's a duplicate
                        if (target != s || freq[target] > 1) {
                            return true;
                        }
                    }
                }

                // If the right suffix is a palindrome, look for the reversed left prefix
                if (isPalindrome(right)) {
                    string target = left;
                    reverse(target.begin(), target.end());
                    
                    if (freq.find(target) != freq.end()) {
                        // Ensure we don't map a string to itself unless there's a duplicate
                        if (target != s || freq[target] > 1) {
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};