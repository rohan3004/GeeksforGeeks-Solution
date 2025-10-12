/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    /**
     * @brief Performs a post-order traversal to calculate candy distribution moves.
     * * @param node The current node in the traversal.
     * @param moves A reference to the total number of moves, which is accumulated.
     * @return The balance of candies for the subtree rooted at 'node'.
     * Balance = (total candies in subtree) - (total nodes in subtree).
     * A positive balance means the subtree has an excess of candies to move up.
     * A negative balance means the subtree has a deficit and needs candies from above.
     */
    int dfs(Node* node, int& moves) {
        // Base case: An empty subtree has no nodes and no candies, so its balance is 0.
        if (node == nullptr) {
            return 0;
        }

        // Recursively calculate the balance for the left and right subtrees.
        int left_balance = dfs(node->left, moves);
        int right_balance = dfs(node->right, moves);

        // The number of moves required is the sum of absolute balances from the children.
        // A balance of +k means k candies move out, -k means k candies move in.
        // Both contribute k moves across the respective edges.
        moves += abs(left_balance) + abs(right_balance);

        // The balance of the current node's subtree is its own excess/deficit
        // (node->data - 1) plus the balances from its children.
        // This value is returned to the parent node.
        return (node->data - 1) + left_balance + right_balance;
    }

    /**
     * @brief Calculates the minimum number of moves to distribute candies evenly, 
     * so that each node has exactly one candy.
     * * @param root The root of the binary tree.
     * @return The minimum number of moves required.
     */
    int distCandy(Node* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};