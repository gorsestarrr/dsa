class DSU {
private:
    vector<int> parent;
    vector<int> sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> rank_(n);
        for (int i = 0; i < n; i++)
            rank_[order[i]] = i;

        DSU dsu(n);
        for (int i = 1; i < n; i++) {
            if (nums[order[i]] - nums[order[i - 1]] <= maxDiff)
                dsu.unite(order[i], order[i - 1]);
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            if (dsu.find(u) != dsu.find(v))
                ans.push_back(-1);
            else
                ans.push_back(abs(rank_[u] - rank_[v]));
        }
        return ans;
    }
};