#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs[0].size();
        for (auto& s : strs) n = min(n, (int)s.size());
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != strs[0][i]) return strs[0].substr(0, i);
            }
        }
        return strs[0].substr(0, n);
    }
};

int main() {
    vector<string> strs = {"flower","flow","flight"};
    auto ans = Solution().longestCommonPrefix(strs);
    cout << ans;
}