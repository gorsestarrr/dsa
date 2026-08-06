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
    int n, k;
    cin >> n >> k;
    vec<ll> h(n);
    for (auto& x : h) cin >> x;

    int l = 0;
    int r = k - 1;
    ll current = 0;
    for (int i = l; i <= r; i++) {
        current += h[i];
    }
    ll min = current;
    int minL = l;
    for (int i = r + 1; i < n; i++) {
        current = current + h[i] - h[l];
        l++;
        r++;
        if (current < min) {
            min = current;
            minL = l;
        }
    }
    cout << minL + 1;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}