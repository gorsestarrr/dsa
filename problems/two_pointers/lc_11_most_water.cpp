#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int best = 0;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            best = max(best, area);
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return best;
    }
};

int main() {
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    auto ans = Solution().maxArea(nums);
    cout << ans;
}