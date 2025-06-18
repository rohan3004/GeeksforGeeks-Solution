class Solution {
public:
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(0, s, current, result);
        return result;
    }

private:
    void backtrack(int start, string &s, vector<string> &current, vector<vector<string>> &result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, current, result);
                current.pop_back(); // backtrack
            }
        }
    }

    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};
