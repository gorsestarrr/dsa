#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const auto& x, const auto& y) {
            return (x[1] - x[0]) < (y[1] - y[0]);
        });
        int n = costs.size() / 2;
        int sum = 0;
        for (int i = 0; i < (int)costs.size(); i++) {
            sum += (i < n) ? costs[i][1] : costs[i][0];
        }
        return sum;
    }
};

int main() {
    vector<vector<int>> costs = {{10,20},{30,200},{400,50},{30,20}};
    auto ans = Solution().twoCitySchedCost(costs);
    cout << ans;
}