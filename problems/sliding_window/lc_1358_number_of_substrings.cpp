#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt[3] = {0, 0, 0};
        int count = 0;
        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && !(cnt[0] && cnt[1] && cnt[2])) {
                ++cnt[s[r] - 'a'];
                ++r;
            }
            if (cnt[0] && cnt[1] && cnt[2]) {
                count += n - r + 1;
            }
            --cnt[s[l] - 'a'];
        }
        return count;
    }
};

int main() {
    string input = "ababbbc";
    auto ans = Solution().numberOfSubstrings(input);
    cout << ans;
}