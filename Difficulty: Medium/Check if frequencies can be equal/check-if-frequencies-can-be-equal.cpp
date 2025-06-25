#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
  public:
    bool sameFreq(string& s) {
        unordered_map<char, int> freq;
        for (size_t i = 0; i < s.size(); ++i) {
            freq[s[i]]++;
        }

        unordered_map<int, int> countFreq;
        for (unordered_map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
            countFreq[it->second]++;
        }

        if (countFreq.size() == 1) return true;  // All same frequency

        if (countFreq.size() == 2) {
            unordered_map<int, int>::iterator it = countFreq.begin();
            int f1 = it->first, c1 = it->second;
            ++it;
            int f2 = it->first, c2 = it->second;

            // Case 1: one frequency is 1 and occurs once
            if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) return true;

            // Case 2: freq difference is 1 and higher freq occurs once
            if (abs(f1 - f2) == 1) {
                if ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)) return true;
            }
        }

        return false;
    }
};
