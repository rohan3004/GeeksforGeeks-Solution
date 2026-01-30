class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        int half = n / 2;

        queue<int> firstHalf;

        // Step 1: Move first half to another queue
        for (int i = 0; i < half; i++) {
            firstHalf.push(q.front());
            q.pop();
        }

        // Step 2: Interleave first half and second half
        while (!firstHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();

            q.push(q.front());
            q.pop();
        }
    }
};
