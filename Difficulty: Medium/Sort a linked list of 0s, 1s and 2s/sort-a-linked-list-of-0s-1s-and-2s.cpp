//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next) 
            return head;  // empty or single-node list
        
        // Dummy heads and tails for three lists: zeros, ones, twos
        Node zeroDummy(0), oneDummy(0), twoDummy(0);
        Node *zeroTail = &zeroDummy, *oneTail = &oneDummy, *twoTail = &twoDummy;
        
        // Partition the list into three lists
        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zeroTail->next = curr;
                zeroTail = zeroTail->next;
            }
            else if (curr->data == 1) {
                oneTail->next = curr;
                oneTail = oneTail->next;
            }
            else {  // curr->data == 2
                twoTail->next = curr;
                twoTail = twoTail->next;
            }
            curr = curr->next;
        }
        
        // Now splice together: zeros → ones → twos
        // Connect end of zeros list to start of ones (or to twos if no ones)
        zeroTail->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;
        // Connect end of ones list to start of twos
        oneTail->next = twoDummy.next;
        // Terminate the final list
        twoTail->next = nullptr;
        
        // New head is start of zeros list if non-empty, otherwise start of ones or twos
        return zeroDummy.next ? zeroDummy.next
             : (oneDummy.next ? oneDummy.next : twoDummy.next);
    }
};




//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends