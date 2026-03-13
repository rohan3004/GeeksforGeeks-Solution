class Solution {
private:
    void backtrack(const string& s, int start, int parts, string current_ip, vector<string>& result) {
        // Base Case: If we have 4 parts and we've consumed the whole string
        if (parts == 4 && start == s.length()) {
            current_ip.pop_back(); // Remove the trailing dot
            result.push_back(current_ip);
            return;
        }
        
        // If we have 4 parts but haven't finished the string, or vice versa
        if (parts == 4 || start == s.length()) {
            return;
        }

        // Explore length 1 to 3 for the current part
        for (int len = 1; len <= 3; ++len) {
            // Prevent out of bounds
            if (start + len > s.length()) break;
            
            string part = s.substr(start, len);
            
            // Check for leading zero rule
            // If length is > 1, the first digit cannot be '0'
            if (part.length() > 1 && part[0] == '0') break; 
            
            // Check if the segment is within the valid IP range (0 - 255)
            if (stoi(part) > 255) break;
            
            // Recurse to find the next parts
            backtrack(s, start + len, parts + 1, current_ip + part + ".", result);
        }
    }

public:
    vector<string> generateIp(string &s) {
        vector<string> result;
        
        // Quick optimization: A valid IP needs at least 4 digits and at most 12 digits
        if (s.length() < 4 || s.length() > 12) {
            return result; 
        }
        
        // Start backtracking from index 0 with 0 parts found
        backtrack(s, 0, 0, "", result);
        
        return result;
    }
};