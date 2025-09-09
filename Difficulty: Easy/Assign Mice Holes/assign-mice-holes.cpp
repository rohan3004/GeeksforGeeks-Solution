#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
 public:
int assignHole(std::vector<int>& mices, std::vector<int>& holes) {

std::sort(mices.begin(), mices.end());
std::sort(holes.begin(), holes.end());

int maxTime = 0;

for (size_t i = 0; i < mices.size(); ++i) {
maxTime = std::max(maxTime, std::abs(mices[i] - holes[i]));
}

return maxTime;
}
};