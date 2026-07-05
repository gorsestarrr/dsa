#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end());
        long long hi = accumulate(nums.begin(), nums.end(), 0LL);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canSplit(nums, k, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
private:
    bool canSplit(vector<int>& nums, int k, int limit) {
        int count = 1;
        long long curSum = 0;
        for (int x : nums) {
            if (curSum + x > limit) {
                count++;
                curSum = x;
                if (count > k) {
                    return false;
                }
            } else {
                curSum += x;
            }
        }
        return true;
    }
};

int main() {
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    auto ans = Solution().splitArray(nums, 2);
    cout << ans;
}