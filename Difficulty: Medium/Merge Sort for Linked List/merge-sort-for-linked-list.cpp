/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
private:
    /**
     * @brief Merges two sorted linked lists into a single sorted list.
     * @param left The head of the first sorted list.
     * @param right The head of the second sorted list.
     * @return The head of the merged sorted list.
     */
    Node* merge(Node* left, Node* right) {
        // A dummy node to act as the starting point of the merged list.
        Node dummy(0);
        Node* tail = &dummy;

        // Traverse both lists and append the smaller node to the tail.
        while (left != nullptr && right != nullptr) {
            if (left->data <= right->data) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        // If one list is exhausted, append the remainder of the other list.
        if (left != nullptr) {
            tail->next = left;
        } else {
            tail->next = right;
        }

        return dummy.next;
    }

public:
    /**
     * @brief Sorts a linked list using the Merge Sort algorithm.
     * @param head The head of the linked list to be sorted.
     * @return The head of the sorted linked list.
     */
    Node* mergeSort(Node* head) {
        // Base case: If the list is empty or has only one element,
        // it is already sorted.
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // --- 1. Divide: Find the middle and split the list ---
        Node* slow = head;
        Node* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // After the loop, 'slow' is the node before the midpoint.
        Node* right_half = slow->next;
        slow->next = nullptr; // Split the list into two halves.

        // --- 2. Conquer: Recursively sort the two halves ---
        Node* left_sorted = mergeSort(head);
        Node* right_sorted = mergeSort(right_half);

        // --- 3. Combine: Merge the two sorted halves ---
        return merge(left_sorted, right_sorted);
    }
};