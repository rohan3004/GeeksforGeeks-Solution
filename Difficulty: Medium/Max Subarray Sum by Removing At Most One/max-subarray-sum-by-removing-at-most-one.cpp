class Solution {
public:
    int maxSumSubarray(vector<int>& arr) {
        if (arr.empty()) return 0;
        
        // Base case for the first element
        int not_skipped = arr[0];
        
        // Initialize skipped to a very small number to avoid underflow
        // We use -1e9 because the min value is -1000, avoiding INT_MIN underflow
        int skipped = -1e9; 
        
        int max_sum = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            // Calculate the new skipped state: 
            // It's either we skip the CURRENT element (meaning we take previous not_skipped), 
            // OR we skipped an element PREVIOUSLY (so we add current arr[i] to previous skipped).
            int new_skipped = max(skipped + arr[i], not_skipped);
            
            // Standard Kadane's for the not_skipped state
            int new_not_skipped = max(not_skipped + arr[i], arr[i]);
            
            // Update states
            skipped = new_skipped;
            not_skipped = new_not_skipped;
            
            // The max sum at this point is the best out of both scenarios
            max_sum = max({max_sum, not_skipped, skipped});
        }
        
        return max_sum;
    }
};