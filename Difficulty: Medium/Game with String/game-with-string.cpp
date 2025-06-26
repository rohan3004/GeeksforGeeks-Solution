#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(string &s, int k) {
        unordered_map<char, int> freq;
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        // Max heap to store frequencies
        priority_queue<int> pq;
        for (unordered_map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
            pq.push(it->second);
        }

        while (k-- && !pq.empty()) {
            int top = pq.top();
            pq.pop();
            if (top > 1)
                pq.push(top - 1);
        }

        int result = 0;
        while (!pq.empty()) {
            int f = pq.top();
            pq.pop();
            result += f * f;
        }

        return result;
    }
};
