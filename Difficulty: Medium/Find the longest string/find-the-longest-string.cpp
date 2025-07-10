class Solution {
  public:
    string longestString(vector<string> &words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        
        // Sort: longer first, then lexicographically smaller
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            if (a.length() != b.length()) return a.length() > b.length();
            return a < b;
        });

        for (const string &word : words) {
            bool allPrefixesExist = true;
            for (int i = 1; i < word.length(); ++i) {
                if (wordSet.find(word.substr(0, i)) == wordSet.end()) {
                    allPrefixesExist = false;
                    break;
                }
            }
            if (allPrefixesExist) return word;
        }

        return "";
    }
};
