class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        queue<int> police, thieves;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') {
                police.push(i);
            } else if (arr[i] == 'T') {
                thieves.push(i);
            }

            // Try to match current policemen and thieves
            while (!police.empty() && !thieves.empty()) {
                int p = police.front();
                int t = thieves.front();

                if (abs(p - t) <= k) {
                    count++;
                    police.pop();
                    thieves.pop();
                } else if (t < p) {
                    thieves.pop();
                } else {
                    police.pop();
                }
            }
        }

        return count;
    }
};
