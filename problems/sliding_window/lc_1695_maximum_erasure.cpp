#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> window;
        int n = nums.size();
        int left = 0, right = 0;
        int best = 0, sum = 0;
        for (right = 0; right < n; ++right) {
            while (window.count(nums[right])) {
                window.erase(nums[left]);
                sum -= nums[left];
                ++left;
            }
            window.insert(nums[right]);
            sum += nums[right];
            best = max(best, sum);
        }
        return best;
    }
};

int main() {
    vector<int> nums = {5,2,1,2,5,2,1,2,5};
    auto ans = Solution().maximumUniqueSubarray(nums);
    cout << ans;
}