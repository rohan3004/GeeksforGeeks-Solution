class Solution {
  public:
    void backtrack(vector<int>& arr, vector<int>& curr,
                   vector<bool>& used, vector<vector<int>>& result) {
        if (curr.size() == arr.size()) {
            result.push_back(curr);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            curr.push_back(arr[i]);

            backtrack(arr, curr, used, result);

            curr.pop_back();     // backtrack
            used[i] = false;
        }
    }

    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> used(arr.size(), false);

        backtrack(arr, curr, used, result);
        return result;
    }
};
