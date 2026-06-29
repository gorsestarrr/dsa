#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& p : patterns) {
            if (word.find(p) != string::npos) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    vector<string> patterns = {"a","abc","bc","d"};
    string word = "abc";
    auto ans = Solution().numOfStrings(patterns, word);
    cout << ans;
}