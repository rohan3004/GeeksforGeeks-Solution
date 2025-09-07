#include <vector>
#include <queue>

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

// A custom comparator struct to create a min-heap of Node pointers.
// It compares nodes based on their 'data' value.
struct CompareNode {
    bool operator()(const Node* a, const Node* b) const {
        // Return true if 'a' should come after 'b' in a min-priority queue.
        return a->data > b->data;
    }
};

class Solution {
 public:
    Node* mergeKLists(std::vector<Node*>& arr) {
        // Create a min-priority queue using our custom comparator.
        std::priority_queue<Node*, std::vector<Node*>, CompareNode> pq;

        // Add the head of each non-empty list to the priority queue.
        for (Node* listHead : arr) {
            if (listHead != nullptr) {
                pq.push(listHead);
            }
        }

        // If the priority queue is empty, all lists were empty.
        if (pq.empty()) {
            return nullptr;
        }

        // Create a dummy node to simplify building the new list.
        Node* dummyHead = new Node(0);
        Node* tail = dummyHead;

        // Process nodes until the priority queue is empty.
        while (!pq.empty()) {
            // Get the node with the smallest value.
            Node* minNode = pq.top();
            pq.pop();

            // Append it to our result list.
            tail->next = minNode;
            tail = tail->next;

            // If the extracted node has a successor, add it to the queue.
            if (minNode->next != nullptr) {
                pq.push(minNode->next);
            }
        }

        // The merged list starts after the dummy head.
        Node* resultHead = dummyHead->next;
        delete dummyHead; // Free the memory allocated for the dummy node.
        
        return resultHead;
    }
};