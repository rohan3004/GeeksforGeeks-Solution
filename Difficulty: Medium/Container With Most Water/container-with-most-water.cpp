class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // Handle the edge case where there are fewer than two lines.
        if (arr.size() < 2) {
            return 0;
        }

        // Initialize two pointers, one at the beginning and one at the end.
        int left = 0;
        int right = arr.size() - 1;
        
        // This variable will store the maximum area found so far.
        int max_area = 0;

        // Loop until the two pointers meet.
        while (left < right) {
            // Calculate the area for the current pair of lines.
            // The width is the distance between the pointers (right - left).
            // The height is limited by the shorter of the two lines.
            int current_height = min(arr[left], arr[right]);
            int current_width = right - left;
            int current_area = current_height * current_width;

            // Update the maximum area if the current area is larger.
            max_area = max(max_area, current_area);

            // The core logic: move the pointer of the shorter line inward.
            // This is because moving the taller line's pointer can't create a larger area,
            // as the height is always limited by the shorter line, and the width will decrease.
            // Our only chance to find a larger area is by moving the shorter line's pointer,
            // hoping to find a taller line.
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};