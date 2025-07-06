#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        typedef tuple<int, int, int> T;

        priority_queue<T> maxHeap;
        set<pair<int, int>> visited;

        maxHeap.push(make_tuple(a[0] + b[0], 0, 0));
        visited.insert(make_pair(0, 0));

        vector<int> result;

        while (k-- && !maxHeap.empty()) {
            T current = maxHeap.top();
            maxHeap.pop();

            int sum = get<0>(current);
            int i = get<1>(current);
            int j = get<2>(current);

            result.push_back(sum);

            // Next: (i+1, j)
            if (i + 1 < n && visited.find(make_pair(i + 1, j)) == visited.end()) {
                maxHeap.push(make_tuple(a[i + 1] + b[j], i + 1, j));
                visited.insert(make_pair(i + 1, j));
            }

            // Next: (i, j+1)
            if (j + 1 < n && visited.find(make_pair(i, j + 1)) == visited.end()) {
                maxHeap.push(make_tuple(a[i] + b[j + 1], i, j + 1));
                visited.insert(make_pair(i, j + 1));
            }
        }

        return result;
    }
};
