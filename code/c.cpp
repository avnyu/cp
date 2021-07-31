#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(u, v) \
    for (auto x = u; x != v;) cout << (*x) << " \n"[++x == v];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1 << 20;
vi st(N << 1), lz(N << 1);

void push(int i) {
    if (!lz[i]) return;

    st[i << 1] += lz[i];
    lz[i << 1] += lz[i];

    st[i << 1 | 1] += lz[i];
    lz[i << 1 | 1] += lz[i];

    lz[i] = 0;
}
void add(int l, int r, int v, int i = 1, int b = 0, int e = N - 1) {
    if (l > e || r < b) return;
    if (l <= b && e <= r) {
        st[i] += v;
        lz[i] += v;
        return;
    }
    push(i);
    int m = (b + e) >> 1;
    add(l, r, v, i << 1, b, m);
    add(l, r, v, i << 1 | 1, m + 1, e);
    st[i] = min(st[i << 1], st[i << 1 | 1]);
}
void solve() {
    int n, m;
    cin >> n >> m;

    vi l(n), r(n), w(n);
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i] >> w[i];

    vi p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int u, int v) { return w[u] < w[v]; });

    int i = 0, j = 0, res = INT_MAX;
    for (i = 0; i < n; ++i) {
        while (j < n && st[1] == 0) {
            add(l[p[j]], r[p[j]] - 1, 1, 1, 1, m - 1);
            j += 1;
        }

        if (st[1] > 0) {
            res = min(res, w[p[j - 1]] - w[p[i]]);
        }

        add(l[p[i]], r[p[i]] - 1, -1, 1, 1, m - 1);
    }

    print(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve();

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}