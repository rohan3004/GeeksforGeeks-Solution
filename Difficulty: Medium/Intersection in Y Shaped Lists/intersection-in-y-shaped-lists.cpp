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
    Node* intersectPoint(Node* head1, Node* head2) {
        // Edge case: if either list is empty, no intersection
        if (head1 == NULL || head2 == NULL) return NULL;

        Node* ptr1 = head1;
        Node* ptr2 = head2;

        // Traverse until the pointers meet.
        // If they don't intersect, they will eventually both become NULL 
        // (assuming we didn't have the guarantee that an intersection exists).
        while (ptr1 != ptr2) {
            
            // If ptr1 reaches end of list A, redirect to head of list B
            if (ptr1 == NULL) {
                ptr1 = head2;
            } else {
                ptr1 = ptr1->next;
            }

            // If ptr2 reaches end of list B, redirect to head of list A
            if (ptr2 == NULL) {
                ptr2 = head1;
            } else {
                ptr2 = ptr2->next;
            }
        }

        // Return the meeting node
        return ptr1;
    }
};