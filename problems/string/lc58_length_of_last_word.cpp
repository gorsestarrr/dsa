#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int c = 0;
        while (s[i] == ' ' && i >= 0)  {
            i--;
        }
        while (s[i] != ' ' && i >= 0) {
            i--;
            c++;
        }
        return c;
    }
};

int main() {
    string word = "a";
    auto ans = Solution().lengthOfLastWord(word);
    cout << ans << endl;
}