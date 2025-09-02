/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // --- 1. Count nodes and handle trivial cases ---
        if (!head || !head->next) {
            return head;
        }

        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // --- 2. Validate k and handle self-swap case ---
        if (k > n) {
            return head; // Not possible to swap
        }
        
        // If k-th from beginning and end are the same node
        if (2 * k - 1 == n) {
            return head;
        }

        // --- 3. Find the two nodes and their predecessors ---
        
        // Find x-th node (k-th from start)
        Node* prev_x = nullptr;
        Node* curr_x = head;
        for (int i = 1; i < k; i++) {
            prev_x = curr_x;
            curr_x = curr_x->next;
        }

        // Find y-th node (k-th from end, which is (n-k+1)-th from start)
        Node* prev_y = nullptr;
        Node* curr_y = head;
        for (int i = 1; i < (n - k + 1); i++) {
            prev_y = curr_y;
            curr_y = curr_y->next;
        }

        // --- 4. Perform the swap by rearranging pointers ---
        
        // Update predecessors' next pointers
        if (prev_x) {
            prev_x->next = curr_y;
        }
        if (prev_y) {
            prev_y->next = curr_x;
        }

        // Update swapped nodes' next pointers
        Node* temp_next = curr_x->next;
        curr_x->next = curr_y->next;
        curr_y->next = temp_next;
        
        // Update head if k=1 or k=n was swapped
        if (k == 1) {
            head = curr_y;
        }
        if (k == n) {
            head = curr_x;
        }
        
        return head;
    }
};