//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

// class Solution {
//   public:
//     int maxXor(vector<int> &arr) {
//         // code here
        
//     }
// };

class Solution {
  struct TrieNode {
    TrieNode* child[2];
    TrieNode() { child[0] = child[1] = nullptr; }
  };
  
  // Inserts x into the trie.
  void insert(TrieNode* root, int x) {
    for (int b = 20; b >= 0; --b) {
      int bit = (x >> b) & 1;
      if (!root->child[bit])
        root->child[bit] = new TrieNode();
      root = root->child[bit];
    }
  }
  
  // Given x, finds the maximum XOR we can get by pairing x
  // with any number already inserted in the trie.
  int queryMaxXor(TrieNode* root, int x) {
    int ans = 0;
    for (int b = 20; b >= 0; --b) {
      int bit = (x >> b) & 1;
      // we'd like to go to the opposite bit if it exists
      int want = bit ^ 1;
      if (root->child[want]) {
        ans |= (1 << b);
        root = root->child[want];
      } else {
        root = root->child[bit];
      }
    }
    return ans;
  }

 public:
  int maxXor(vector<int> &arr) {
    TrieNode* root = new TrieNode();
    // 1) Build trie of all numbers
    for (int x : arr) {
      insert(root, x);
    }
    // 2) For each number, find the best partner
    int best = 0;
    for (int x : arr) {
      best = max(best, queryMaxXor(root, x));
    }
    return best;
  }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends