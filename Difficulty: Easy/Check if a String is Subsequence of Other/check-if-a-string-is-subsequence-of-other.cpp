class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        int i = 0; // Pointer for s1
        int j = 0; // Pointer for s2
        
        // Get the lengths of the strings
        int n1 = s1.length();
        int n2 = s2.length();
        
        // Traverse s2 and s1
        while (i < n1 && j < n2) {
            // If the characters match, increment the pointer for s1
            if (s1[i] == s2[j]) {
                i++;
            }
            // Always increment the pointer for s2 to continue searching
            j++;
        }
        
        // If i equals the length of s1, it means we found
        // all characters of s1 in s2 in the correct order.
        return i == n1;
    }
};