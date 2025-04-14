//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string>& words) {
            unordered_map<char, unordered_set<char>> adjList;
            unordered_map<char, int> inDegree;
            unordered_set<char> allChars;
    
            // Initialize the graph
            for (const string& word : words) {
                for (char c : word) {
                    allChars.insert(c);
                    inDegree[c] = 0;
                }
            }
    
            // Build the graph and calculate in-degrees
            for (size_t i = 0; i < words.size() - 1; ++i) {
                string w1 = words[i];
                string w2 = words[i + 1];
                size_t len = min(w1.length(), w2.length());
                bool foundDifference = false;
    
                for (size_t j = 0; j < len; ++j) {
                    char c1 = w1[j];
                    char c2 = w2[j];
                    if (c1 != c2) {
                        if (adjList[c1].find(c2) == adjList[c1].end()) {
                            adjList[c1].insert(c2);
                            ++inDegree[c2];
                        }
                        foundDifference = true;
                        break;
                    }
                }
    
                // If w2 is a prefix of w1 and w1 > w2, it's invalid
                if (!foundDifference && w1.length() > w2.length()) {
                    return "";
                }
            }
    
            // Topological sort (Kahn's Algorithm)
            queue<char> q;
            for (char c : allChars) {
                if (inDegree[c] == 0) {
                    q.push(c);
                }
            }
    
            string order;
            while (!q.empty()) {
                char current = q.front();
                q.pop();
                order += current;
    
                for (char neighbor : adjList[current]) {
                    --inDegree[neighbor];
                    if (inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
    
            // If the order doesn't include all characters, there's a cycle
            if (order.length() != allChars.size()) {
                return "";
            }
    
            return order;
        }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends