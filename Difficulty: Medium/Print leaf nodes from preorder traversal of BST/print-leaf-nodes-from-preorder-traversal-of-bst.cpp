class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> leaves;
        int index = 0;
        findLeaves(preorder, index, INT_MIN, INT_MAX, leaves);
        return leaves;
    }

    void findLeaves(const vector<int>& preorder, int& index, int minVal, int maxVal, vector<int>& leaves) {
        if (index >= preorder.size()) return;

        int val = preorder[index];
        if (val < minVal || val > maxVal) return;

        index++;
        int leftIndex = index;
        findLeaves(preorder, index, minVal, val - 1, leaves); // left subtree
        int rightIndex = index;
        findLeaves(preorder, index, val + 1, maxVal, leaves); // right subtree

        // If both recursive calls did not consume any new node, it's a leaf
        if (leftIndex == rightIndex && rightIndex == index) {
            leaves.push_back(val);
        }
    }
};
