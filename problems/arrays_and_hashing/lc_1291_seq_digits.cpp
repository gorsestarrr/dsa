#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        int startDigits = (int)log10(low) + 1;
        int endDigits = (int)log10(high) + 1;
        for (int len = startDigits; len <= endDigits; ++len) {
            long long base = 0;
            for (int j = 1; j <= len; j++) {
                base = base * 10 + j;
            }
            long long step = 0;
            for (int k = 0; k < len; k++) {
                step = step * 10 + 1;
            }
            int count = 10 - len;
            long long cur = base;
            for (int c = 0; c < count; c++) {
                if (cur >= low && cur <= high) {
                    result.push_back((int)cur);
                }
                cur += step;
            }
        }
        return result;
    }
};

int main() {
    auto ans = Solution().sequentialDigits(1000, 13000);
    cout << ans[0];
}