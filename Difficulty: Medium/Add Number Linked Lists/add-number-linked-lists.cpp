/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Helper function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        // Step 1: Reverse both input lists to handle addition from LSD
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        Node* resHead = NULL;
        Node* resTail = NULL;
        int carry = 0;
        
        // Step 2: Add lists node by node
        while (head1 != NULL || head2 != NULL || carry != 0) {
            int val1 = (head1 != NULL) ? head1->data : 0;
            int val2 = (head2 != NULL) ? head2->data : 0;
            
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            Node* newNode = new Node(digit);
            
            if (resHead == NULL) {
                resHead = newNode;
                resTail = newNode;
            } else {
                resTail->next = newNode;
                resTail = newNode; // Move tail
            }
            
            if (head1) head1 = head1->next;
            if (head2) head2 = head2->next;
        }
        
        // Step 3: Reverse the result to get back to MSD -> LSD order
        Node* finalHead = reverse(resHead);
        
        // Step 4: Remove leading zeros (e.g., 0 -> 0 -> 7 -> 0 becomes 7 -> 0)
        // We ensure we don't remove a node if it is the only node left (handle single "0")
        while (finalHead != NULL && finalHead->data == 0 && finalHead->next != NULL) {
            Node* temp = finalHead;
            finalHead = finalHead->next;
            delete temp; // Clean up memory
        }
        
        return finalHead;
    }
};