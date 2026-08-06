#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> prefSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefSum[i + 1] = prefSum[i] + (s[i] != '0' ? s[i] - '0' : 0);
        vector<int> pos;
        vector<long long> P;
        vector<long long> pw;
        P.push_back(0);
        pw.push_back(1);
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                P.push_back((P.back() * 10 + (s[i] - '0')) % MOD);
                pw.push_back(pw.back() * 10 % MOD);
            }
        }

        vector<int> result;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long sum = prefSum[r + 1] - prefSum[l];

            int lo = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int hi = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

            long long x = 0;
            if (lo < hi) {
                int len = hi - lo;
                x = ((P[hi] - P[lo] * pw[len]) % MOD + MOD) % MOD;
            }

            long long total = x * (sum % MOD) % MOD;
            result.push_back((int)total);
        }
        return result;
    }
};

int main() {
    vector<vector<int>> queries = {{0,9}};
    string s = "9876543210";
    auto ans = Solution().sumAndMultiply(s, queries);
    cout << ans[0];
    return 0;
}