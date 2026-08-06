#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T> using vec  = vector<T>;
template <class T> using vv   = vector<vector<T>>;
template <class T> using minq = priority_queue<T, vector<T>, greater<T>>;

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)   ((int)(x).size())

constexpr ll INF  = 4e18;
constexpr int IINF = 2e9;
constexpr int MOD = 1'000'000'007;


void solve() {
    string s;
    cin >> s;
    stack<char> st;
    unordered_map<char, char> matchings = { {')','('}, {']','['}, {'}','{'}, {'>','<'}};
    int replacements = 0;
    for(auto& c : s) {
        if (matchings.count(c)) {
            if (st.empty()) {
                cout << "Impossible";
                return;
            }
            if (matchings[c] != st.top()) {
                replacements++;
            }
            st.pop();
        } else {
            st.push(c);
        }
    }
    st.empty() ? cout << replacements : cout << "Impossible";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}