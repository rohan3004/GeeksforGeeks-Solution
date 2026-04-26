class Solution {
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int i = 0, j = 0, k = 0;
        vector<int> result;
        
        int n1 = a.size();
        int n2 = b.size();
        int n3 = c.size();
        
        while (i < n1 && j < n2 && k < n3) {
            // If all three elements are equal
            if (a[i] == b[j] && b[j] == c[k]) {
                // Avoid inserting duplicates
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
                j++;
                k++;
            }
            // If a[i] is smaller than b[j], advance pointer for array a
            else if (a[i] < b[j]) {
                i++;
            }
            // If b[j] is smaller than c[k], advance pointer for array b
            else if (b[j] < c[k]) {
                j++;
            }
            // Otherwise, c[k] is the smallest, advance pointer for array c
            else {
                k++;
            }
        }
        
        return result;
    }
};