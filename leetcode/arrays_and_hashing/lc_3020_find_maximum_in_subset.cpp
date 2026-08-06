#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<ll,int> cnt;
        cnt.reserve(nums.size());
        for (int x : nums) {
            ++cnt[x];
        }
        int best = 1;
        for (auto [num, c] :cnt) {
            if (num == 1) {
                best = max(best, c % 2 ? c : c - 1);
                continue;
            }
            int length = 0;
            ll current = num;
            while (cnt.count(current) && cnt[current] >= 2) {
                length += 2;
                current = current * current;
            }
            length += cnt.count(current) ? 1 : -1;
            best = max(best, length);
        }
        return best;
    }
};

int main() {
    vector<int> nums = {2,4,2,4,16};
    auto ans = Solution().maximumLength(nums);
    cout << ans;
}