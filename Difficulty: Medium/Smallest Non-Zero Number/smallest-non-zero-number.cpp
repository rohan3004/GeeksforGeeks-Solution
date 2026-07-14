class Solution {
public:
    int find(vector<int>& arr) {
        int req = 0;
        
        // Traverse the array backwards
        for (int i = arr.size() - 1; i >= 0; --i) {
            // Equivalent to ceil((req + arr[i]) / 2.0)
            req = (req + arr[i] + 1) / 2;
        }
        
        return req;
    }
};