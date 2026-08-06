#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, long long> mp;
        long long ans = 0;
        for (string s : words) {
            int shift = s[0] - 'a';
            for (char& c : s) {
                c = 'a' + (c - 'a' - shift + 26) % 26;
            }
            ans += mp[s];
            mp[s]++;
        }
        return ans;
    }
};

int main() {
    vector<string> strs = {"fusion","layout"};
    auto ans = Solution().countPairs(strs);
    cout << ans;
}
