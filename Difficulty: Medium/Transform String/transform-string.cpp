class Solution {
public:
    int transform(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();

        // If lengths are different, it's impossible
        if (n != m) return -1;

        // Array to count character frequencies
        int count[256] = {0};

        // Increment for s1 and decrement for s2
        for (int i = 0; i < n; i++) {
            count[s1[i]]++;
            count[s2[i]]--;
        }

        // If any count is not 0, characters don't match
        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) {
                return -1;
            }
        }

        // Two pointer approach from the end
        int i = n - 1;
        int j = n - 1;
        int res = 0;

        while (i >= 0) {
            // If characters match, move both pointers
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } 
            // If they don't match, this character in s1 needs to be moved to the front
            else {
                i--;
                res++;
            }
        }

        return res;
    }
};