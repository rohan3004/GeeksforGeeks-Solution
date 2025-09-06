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
    int lengthOfLoop(Node *head) {
        // Handle edge cases: empty list or single-node list
        if (!head || !head->next) {
            return 0;
        }

        Node *slow = head;
        Node *fast = head;

        // 1. Detect the loop using Floyd's Cycle-Finding Algorithm
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, a loop is detected
            if (slow == fast) {
                // 2. Calculate the length of the loop
                int length = 1;
                Node *temp = slow->next;
                
                // Traverse the loop until we reach the meeting point again
                while (temp != slow) {
                    length++;
                    temp = temp->next;
                }
                return length;
            }
        }

        // If the loop finishes, fast has reached the end, so no loop exists
        return 0;
    }
};