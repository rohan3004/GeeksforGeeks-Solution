class Solution {
  public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        // We need at least one bar between left and right, 
        // so we loop while left is strictly less than right - 1
        while (left < right - 1) {
            // Calculate the number of bars between the two pointers
            int width = right - left - 1;
            
            // The height of the rectangle is dictated by the shorter bar
            int current_area = min(height[left], height[right]) * width;
            
            // Update the maximum area
            max_area = max(max_area, current_area);

            // Move the pointer of the shorter bar inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};