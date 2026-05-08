#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to check if a string has valid parentheses
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
            }
            // If count drops below 0, there are more closing than opening parentheses
            if (count < 0) return false;
        }
        return count == 0;
    }

public:
    vector<string> validParenthesis(string &s) {
        vector<string> result;
        if (s.empty()) return {""};

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);
        bool found = false;

        // BFS traversal
        while (!q.empty()) {
            int size = q.size();
            vector<string> currentLevelValid;

            // Process all strings at the current level (current number of removals)
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    currentLevelValid.push_back(curr);
                    found = true;
                }

                // If we've found valid strings at this level, 
                // we don't need to generate further children for the next level.
                if (found) continue;

                // Generate children by removing one parenthesis at a time
                for (int j = 0; j < curr.length(); ++j) {
                    // Skip if it's a lowercase English letter
                    if (curr[j] != '(' && curr[j] != ')') continue;
                    
                    // Create the new string without the j-th character
                    string nextStr = curr.substr(0, j) + curr.substr(j + 1);
                    
                    if (visited.find(nextStr) == visited.end()) {
                        visited.insert(nextStr);
                        q.push(nextStr);
                    }
                }
            }

            // If we found valid strings at this level, break out of the BFS
            if (found) {
                result = currentLevelValid;
                break;
            }
        }

        // Edge case: if nothing valid was found (e.g., all parentheses were invalid)
        if (result.empty()) {
            return {""};
        }
        
        // Sort the result to ensure lexicographical order
        sort(result.begin(), result.end());
        return result;
    }
};