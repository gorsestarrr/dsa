#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                --k;
            }
            st.push_back(c);
        }
        st.resize(st.size() - k);
        st.erase(0, st.find_first_not_of('0'));
        return st.empty() ? "0" : st;
    }
};

int main() {
    string num  = "1221";
    int k = 2;
    auto ans = Solution().removeKdigits(num, k);
    cout << ans << endl;
}