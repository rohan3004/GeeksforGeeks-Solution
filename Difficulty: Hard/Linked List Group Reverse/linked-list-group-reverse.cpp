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
 public:
   Node *reverseKGroup(Node *head, int k) {
       // If the list is empty, has only one node, or k is 1, no change is needed.
       if (!head || !head->next || k == 1) {
           return head;
       }

       Node* current = head;
       Node* newHead = nullptr;
       Node* tailOfPreviousGroup = nullptr;

       // Traverse the entire list.
       while (current != nullptr) {
           // 'headOfCurrentGroup' will become the tail of the reversed group.
           Node* headOfCurrentGroup = current;
           Node* groupPrev = nullptr;
           int count = 0;
           
           // Reverse one group of size up to k.
           // This loop also handles the last group which might be smaller than k.
           while (current != nullptr && count < k) {
               Node* nextNode = current->next;
               current->next = groupPrev;
               groupPrev = current;
               current = nextNode;
               count++;
           }

           // After reversal, 'groupPrev' is the new head of the current group.
           
           // If this was the first group, its head is the new head of the entire list.
           if (newHead == nullptr) {
               newHead = groupPrev;
           } else {
               // Connect the tail of the previous reversed group to the head of the current reversed group.
               tailOfPreviousGroup->next = groupPrev;
           }

           // The original head of this group is now its tail.
           // We'll need it to connect to the next group in the next iteration.
           tailOfPreviousGroup = headOfCurrentGroup; 
       }
       
       return newHead;
   }
};