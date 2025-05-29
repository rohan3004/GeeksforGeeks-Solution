class Solution {
  public:
    void dfs(Node* node, int currSum, int currLen, int& maxSum, int& maxLen) {
        if (!node) return;

        currSum += node->data;
        currLen++;

        // If it's a leaf node
        if (!node->left && !node->right) {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxSum = currSum;
            } else if (currLen == maxLen) {
                maxSum = max(maxSum, currSum);
            }
            return;
        }

        // Recur for left and right children
        dfs(node->left, currSum, currLen, maxSum, maxLen);
        dfs(node->right, currSum, currLen, maxSum, maxLen);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int maxSum = 0;
        int maxLen = 0;
        dfs(root, 0, 0, maxSum, maxLen);
        return maxSum;
    }
};
