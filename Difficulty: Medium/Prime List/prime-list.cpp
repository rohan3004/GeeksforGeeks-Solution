//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

class Solution {
  public:
    vector<bool> sieve(int maxVal) {
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxVal; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxVal; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    Node *primeList(Node *head) {
        const int MAX = 10000 + 100;
        vector<bool> isPrime = sieve(MAX);
        vector<int> primes;
        
        for (int i = 2; i <= MAX; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }

        Node* curr = head;
        while (curr) {
            if (!isPrime[curr->val]) {
                // Binary search for nearest prime
                auto it = lower_bound(primes.begin(), primes.end(), curr->val);
                int high = (it != primes.end()) ? *it : INT_MAX;
                int low = (it != primes.begin()) ? *(it - 1) : INT_MAX;
                
                if (abs(curr->val - low) <= abs(high - curr->val))
                    curr->val = low;
                else
                    curr->val = high;
            }
            curr = curr->next;
        }

        return head;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends