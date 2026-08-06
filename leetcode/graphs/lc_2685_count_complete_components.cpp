#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            vector<int> component;
            queue<int> queue;
            visited[i] = true;
            queue.push(i);
            while (!queue.empty()) {
                int u = queue.front(); queue.pop();
                component.push_back(u);
                for (auto& v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        queue.push(v);
                    }
                }
            }
            long long totalDegree = 0;
            for (auto& u : component) {
                totalDegree += adj[u].size();
            }
            int n = component.size();
            long long need = n * (n - 1) / 2;
            if (totalDegree / 2 == need) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
    auto ans = Solution().countCompleteComponents(n, edges);
    cout << ans;
}