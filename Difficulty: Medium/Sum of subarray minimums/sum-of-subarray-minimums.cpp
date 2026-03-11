#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();
        
        // Arrays to store the distance to the next/previous smaller elements
        vector<int> left(n);
        vector<int> right(n);
        
        stack<int> s1, s2;
        
        // 1. Find distance to Previous Less Element
        for (int i = 0; i < n; ++i) {
            // Keep popping elements until we find a strictly smaller element
            while (!s1.empty() && arr[s1.top()] >= arr[i]) {
                s1.pop();
            }
            // If stack is empty, it means arr[i] is the smallest so far
            left[i] = s1.empty() ? (i + 1) : (i - s1.top());
            s1.push(i);
        }
        
        // 2. Find distance to Next Less or Equal Element
        for (int i = n - 1; i >= 0; --i) {
            // Keep popping until we find a smaller or equal element
            while (!s2.empty() && arr[s2.top()] > arr[i]) {
                s2.pop();
            }
            // If stack is empty, it means arr[i] is the smallest to the right
            right[i] = s2.empty() ? (n - i) : (s2.top() - i);
            s2.push(i);
        }
        
        // 3. Calculate total sum
        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            // The number of subarrays where arr[i] is minimum is left[i] * right[i]
            long long subarrays_count = 1LL * left[i] * right[i];
            total_sum += subarrays_count * arr[i];
        }
        
        // The problem guarantees the sum fits within a 32-bit unsigned int
        return static_cast<int>(total_sum);
    }
};