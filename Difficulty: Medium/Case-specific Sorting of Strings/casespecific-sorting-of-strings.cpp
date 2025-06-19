class Solution {
  public:
    string caseSort(string& s) {
        vector<char> upper, lower;

        // Separate the characters
        for (char c : s) {
            if (isupper(c)) {
                upper.push_back(c);
            } else {
                lower.push_back(c);
            }
        }

        // Sort each vector
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());

        // Rebuild the result string
        string result;
        int u = 0, l = 0;
        for (char c : s) {
            if (isupper(c)) {
                result += upper[u++];
            } else {
                result += lower[l++];
            }
        }

        return result;
    }
};
