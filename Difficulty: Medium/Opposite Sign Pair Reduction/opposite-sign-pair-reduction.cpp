#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st; // We will use a vector as a stack for easy returning
        
        for (int x : arr) {
            bool destroyed = false;
            
            // While the stack isn't empty and signs are opposite
            // Since arr[i] != 0, (a > 0) != (b > 0) perfectly checks for opposite signs
            while (!st.empty() && (st.back() > 0) != (x > 0)) {
                if (abs(x) > abs(st.back())) {
                    // Current element has a larger absolute value, pop the stack top
                    st.pop_back(); 
                } 
                else if (abs(x) == abs(st.back())) {
                    // Absolute values are equal, both are destroyed
                    st.pop_back();
                    destroyed = true;
                    break;
                } 
                else {
                    // Current element has a smaller absolute value, it gets destroyed
                    destroyed = true;
                    break;
                }
            }
            
            // If the current element wasn't destroyed, add it to the stack
            if (!destroyed) {
                st.push_back(x);
            }
        }
        
        return st;
    }
};