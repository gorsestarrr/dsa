#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        set<int> given (nums.begin(), nums.end());
        set<int> all;
        for (int i = min; i <= max; ++i) {
            all.insert(i);
        }
        vector<int> diff;
        set_difference(
               all.begin(), all.end(),
               given.begin(), given.end(),
               back_inserter(diff)
           );
        return diff;
    }
};

int main() {
    vector<int> nums = {1,4,2,5};
    auto ans = Solution().findMissingElements(nums);
    cout << ans[0] << endl;
}
