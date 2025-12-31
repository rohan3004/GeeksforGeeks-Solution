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

    bool isPalindrome(Node *head) {
        // Edge case: Empty or single node list is a palindrome
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Step 1: Find the middle using Slow and Fast pointers
        Node* slow = head;
        Node* fast = head;

        // Move fast by 2 steps and slow by 1 step
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now at the end of the first half (or exact middle)
        
        

        // Step 2: Reverse the second half
        Node* secondHalfHead = reverse(slow->next);
        
        

        // Step 3: Compare the two halves
        Node* firstHalf = head;
        Node* secondHalf = secondHalfHead;
        
        bool isPalin = true;
        while (secondHalf != NULL) {
            if (firstHalf->data != secondHalf->data) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Optional Step 4: Restore the list (Good practice, but often not strictly required)
        // slow->next = reverse(secondHalfHead);

        return isPalin;
    }
};