#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long value = 0;
        int place = 1;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                sum += digit * place;
                value += digit;
                place *= 10;
            }
            n /= 10;
        }
        return sum * value;
    }
};

int main() {
    int n = 10203004;
    auto ans = Solution().sumAndMultiply(n);
    cout << ans;
}