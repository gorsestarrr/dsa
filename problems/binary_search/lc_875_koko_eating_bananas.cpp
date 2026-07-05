#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (hoursNeeded(piles, mid) <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
private:
    ll hoursNeeded(vector<int>& piles, int k) {
        ll hours = 0;
        for (int p : piles) {
            hours += ceil((double)p / k);
        }
        return hours;
    }
};

int main() {
    vector<int> piles = {30,11,23,4,20};
    int h = 5;
    auto ans = Solution().minEatingSpeed(piles, h);
    cout << ans;
}