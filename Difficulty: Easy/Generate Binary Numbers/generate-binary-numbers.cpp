#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<string> generateBinary(int n) {
        // Create a queue to store binary number strings.
        queue<string> q;

        // Push the first binary number "1" into the queue.
        q.push("1");

        // This vector will store the generated binary numbers.
        vector<string> result;

        // Loop n times to generate n binary numbers.
        for (int i = 0; i < n; i++) {
            // 1. Dequeue the front string and add it to the result.
            string current = q.front();
            q.pop();
            result.push_back(current);

            // 2. Generate the next two binary numbers by appending "0" and "1".
            string next_with_zero = current + "0";
            string next_with_one = current + "1";

            // 3. Enqueue the two new strings for future processing.
            q.push(next_with_zero);
            q.push(next_with_one);
        }

        return result;
    }
};