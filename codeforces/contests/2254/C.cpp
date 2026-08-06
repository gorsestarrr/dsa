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

bool isComplement(unsigned a, unsigned b) {
    unsigned x = a^b;
    return (x & (x + 1)) == 0 && x != 0;
}

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int o1 = 0, e1 = 0, o2 = 0, e2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == '1') {
            i % 2 == 0 ? o1++ : e1++;
        }
        if (s2[i] == '1') {
            i % 2 == 0 ? o2++ : e2++;
        }
    }
    o1 == o2 && e1 == e2 ? YES() : NO();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}