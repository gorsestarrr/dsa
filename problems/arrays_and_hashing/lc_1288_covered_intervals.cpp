#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        int count = 0;
        int max = INT_MIN;
        for (auto& i: intervals) {
            if (i[1] > max) {
                max = i[1];
                ++count;
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 4},{3, 6},{2, 8}};
    auto ans = Solution().removeCoveredIntervals(intervals);
    cout << ans;
    return 0;
}