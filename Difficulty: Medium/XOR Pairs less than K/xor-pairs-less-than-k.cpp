#include <vector>
#include <iostream>

using namespace std;

// Trie Node Definition
struct TrieNode {
    TrieNode* child[2];
    int count; // Stores count of numbers passing through this node

    TrieNode() {
        child[0] = child[1] = nullptr;
        count = 0;
    }
};

class Solution {
private:
    // Helper to insert a number into the Trie
    void insert(TrieNode* root, int num) {
        TrieNode* curr = root;
        // Iterate from 16 down to 0 (since 50000 < 2^16)
        for (int i = 16; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->child[bit]) {
                curr->child[bit] = new TrieNode();
            }
            curr = curr->child[bit];
            curr->count++; // Increment count for this path
        }
    }

    // Helper to count pairs such that XOR < k
    int query(TrieNode* root, int num, int k) {
        TrieNode* curr = root;
        int countPairs = 0;

        for (int i = 16; i >= 0; i--) {
            if (!curr) break;

            int bit_num = (num >> i) & 1;
            int bit_k = (k >> i) & 1;

            if (bit_k == 1) {
                // If k's bit is 1:
                // 1. If we form a 0 (by choosing child[bit_num]), then 0 < 1. 
                //    These paths are strictly smaller than k. Add them all.
                if (curr->child[bit_num]) {
                    countPairs += curr->child[bit_num]->count;
                }
                
                // 2. We continue to the other branch (child[1 - bit_num]) 
                //    to see if we can match the 1 in k but be smaller later.
                curr = curr->child[1 - bit_num];
            } else {
                // If k's bit is 0:
                // We cannot form a 1 here (would be > k).
                // We must form a 0. So we need child[bit_num].
                curr = curr->child[bit_num];
            }
        }
        return countPairs;
    }

public:
    int cntPairs(vector<int>& arr, int k) {
        TrieNode* root = new TrieNode();
        int totalPairs = 0;

        for (int num : arr) {
            // 1. Query existing numbers in Trie
            totalPairs += query(root, num, k);
            
            // 2. Insert current number into Trie
            insert(root, num);
        }

        // Note: In a real environment, you should delete the Trie to free memory
        return totalPairs;
    }
};