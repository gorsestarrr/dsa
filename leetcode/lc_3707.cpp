#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool scoreBalance(string s) {
        int total = 0;
        for (char c: s) {
            int val = c - 'a' + 1;
            total += val;
        }
        int sum1 = s[0] -'a' + 1;
        int sum2 = total - sum1;
        if (sum1 == sum2) {
            return true;
        }
        for (int i = 1; i < s.size() - 1; i++) {
            int diff = s[i] - 'a' + 1;
            sum1 += diff;
            sum2 -= diff;
            if (sum1 == sum2) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    string s = "adcb";
    auto ans = Solution().scoreBalance(s);
    cout << ans;
}
