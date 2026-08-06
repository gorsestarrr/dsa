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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int cnt = 0;

    sort(a.begin(), a.end(), greater<>());
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}