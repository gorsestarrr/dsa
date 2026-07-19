#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const auto& x, const auto& y) {
            if (x[0] == y[0]) {
                return x[1] > y[1];
            }
            return x[0] < y[0];
        });
        vector<vector<int>> queue(people.size(), {-1, -1});
        for (const auto& p : people) {
            int skip = p[1];
            for (int i = 0; i < (int)queue.size(); ++i) {
                if (queue[i][0] == -1) {
                    if (skip == 0) {
                        queue[i] = p;
                        break;
                    }
                    --skip;
                }
            }
        }
        return queue;
    }
};
int main() {
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    auto ans = Solution().reconstructQueue(people);
    return 0;
}