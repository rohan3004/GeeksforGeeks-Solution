#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int> st;
        // Initialize current root as minimum possible value
        int root = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            // If we find a node which is on the right side 
            // and smaller than the root, return false
            if (arr[i] < root) {
                return false;
            }

            // If arr[i] is in the right subtree of stack top,
            // keep removing items smaller than arr[i]
            // and make the last removed item as the new root.
            while (!st.empty() && st.top() < arr[i]) {
                root = st.top();
                st.pop();
            }

            // Push the current node to the stack
            st.push(arr[i]);
        }
        
        return true;
    }
};