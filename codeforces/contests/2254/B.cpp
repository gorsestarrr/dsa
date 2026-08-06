#include <bits/stdc++.h>
using namespace std;
 
using ll  = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T> using vec  = vector<T>;
template <class T> using vv   = vector<vector<T>>;
template <class T> using minq = priority_queue<T, vector<T>, greater<T>>;

#define READ(v) for (auto &x : (v)) cin >> x
#define PRINT(v) for (auto x : (v)) cout << x << ' '; cout << '\n'
#define READ2(mat) for (auto &row : (mat)) READ(row)
#define PRINT2(mat) for (auto &row : (mat)) PRINT(row)

inline void YES() { cout << "YES\n"; }
inline void NO()  { cout << "NO\n"; }

constexpr ll INF  = 4e18;
constexpr int IINF = 2e9;
constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char, int>> b;
    char cur = s[0];
    int curFreq = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == cur) {
            curFreq++;
        } else {
            b.push_back({cur, curFreq});
            curFreq = 1;
            cur = s[i];
        }
    }
    b.push_back({cur, curFreq});
    int best = 0;
    for (int i = 1; i + 1 < (int)b.size(); ++i) {
        if (b[i].second == 1) {
            if (b[i - 1].first == b[i + 1].first) {
                best = 2;
                break;
            }
            best = max(best, 1);
        }
    }
    cout << (int)b.size() - best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}