#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        int n = position.size();
        int low = 1, high = position[n - 1] - position[0];

        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (canPlace(position, m, mid)) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
private:
    bool canPlace(vector<int>& position, int m, int f) {
        int last = position[0];
        int count = 1;
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - last >= f) {
                ++count;
                last = position[i];
                if (count >= m) {
                    return true;
                }
            }
        }
        return count >= m;
    }
};

int main() {
    vector<int> piles = {5,4,3,2,1,1000000000};
    int m = 2;
    auto ans = Solution().maxDistance(piles, m);
    cout << ans;
}