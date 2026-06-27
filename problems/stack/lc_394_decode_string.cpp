#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(const string& s) {
        stack<pair<string, int>> st;
        string cur;
        int num = 0;
        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                num = num * 10 + (ch - '0');
            } else if (ch == '[') {
                st.push({cur, num});
                cur.clear();
                num = 0;
            } else if (ch == ']') {
                auto [prevCur, prevNum] = st.top();
                st.pop();
                string repeated;
                for (int i = 0; i < prevNum; ++i) {
                    repeated += cur;
                }
                cur = prevCur + repeated;
            } else {
                cur += ch;
            }
        }
        return cur;
    }
};

int main() {
    string str = "3[a]2[bc]";
    auto ans = Solution().decodeString(str);
    cout << ans;
}