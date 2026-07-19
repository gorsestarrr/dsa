#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int tank = 0;
        int start = 0;
        for (int i = 0; i < n; ++i) {
            int d = gas[i] - cost[i];
            total += d;
            tank += d;
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};

int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << Solution().canCompleteCircuit(gas, cost);
}