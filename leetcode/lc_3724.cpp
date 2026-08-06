#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF  = 4e18;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        set<ll> candidates;
        ll ops = 0;
        int n = nums1.size();
        ll last = nums2.back();
        for (int i = 0; i < n; ++i) {
            ll left = min(nums1[i], nums2[i]);
            ll right = max(nums1[i], nums2[i]);
            ops += right - left;
            candidates.insert(left);
            candidates.insert(right);
            if (last >= left && last <= right) {
                candidates.insert(last);
            }
        }
        ll minAbs = INF;
        for (ll val : candidates) {
            minAbs = min(minAbs, llabs(last - val));
        }
        return ops + minAbs + 1;
    }
};

int main() {
    vector<int> nums1 = {2};
    vector<int> nums2 = {3, 4};

    cout << Solution().minOperations(nums1, nums2);
}
