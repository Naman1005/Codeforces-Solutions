//  ███▄    █  ▄▄▄       ███▄ ▄███▓ ▄▄▄       ███▄    █
//  ██ ▀█   █ ▒████▄    ▓██▒▀█▀ ██▒▒████▄     ██ ▀█   █
// ▓██  ▀█ ██▒▒██  ▀█▄  ▓██    ▓██░▒██  ▀█▄  ▓██  ▀█ ██▒
// ▓██▒  ▐▌██▒░██▄▄▄▄██ ▒██    ▒██ ░██▄▄▄▄██ ▓██▒  ▐▌██▒
// ▒██░   ▓██░ ▓█   ▓██▒▒██▒   ░██▒ ▓█   ▓██▒▒██░   ▓██░
// ░ ▒░   ▒ ▒  ▒▒   ▓▒█░░ ▒░   ░  ░ ▒▒   ▓▒█░░ ▒░   ▒ ▒
// ░ ░░   ░ ▒░  ▒   ▒▒ ░░  ░      ░  ▒   ▒▒ ░░ ░░   ░ ▒░
//    ░   ░ ░   ░   ▒   ░      ░     ░   ▒      ░   ░ ░
//          ░       ░  ░       ░         ░  ░         ░
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fro(i, x, y) for (ll i = (ll)(x); i <= (ll)(y); i++)
#define pre(i, x, y) for (ll i = (ll)(x); i >= (ll)(y); i--)
#define fact(n) (ll) tgamma(n + 1)
#define truncMod(a, b) (ll)(a - (b * (floor(a / b))))
void inp_out() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
template <typename T, typename = void> struct is_container : false_type {};
template <typename T> struct is_container<T, void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>> : true_type {};
template <typename T1, typename T2> void pr(const pair<T1, T2> &p) { cout << p.first << ' ' << p.second << endl; }
template <typename T> void pr(const T &element) {
    if constexpr (is_same<T, string>::value || is_same_v<decay_t<T>, const char *> || is_same_v<decay_t<T>, char *>)
        cout << element << endl;
    else if constexpr (is_container<T>::value) {
        for (const auto &e : element) pr(e);
        cout << endl;
    } else
        cout << element << ' ';
}
template <typename T, typename... Args> void pr(const T &first, const Args &...args) {
    pr(first);
    pr(args...);
}
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T> void ip(T &element) {
    if constexpr (is_same<T, string>::value)
        cin >> element;
    else if constexpr (is_container<T>::value) {
        for (auto &e : element) ip(e);
    } else
        cin >> element;
}
template <typename T, typename... Args> void ip(T &first, Args &...args) {
    ip(first);
    ip(args...);
}
class DSU {
    vll parent, size;
 public:
    DSU(ll n) {
        parent.resize(n);
        size.resize(n, 1);
        for (ll i = 0; i < n; i++) parent[i] = i;
    }
    ll find(ll i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    void unite(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (size[a] < size[b])
            parent[a] = b, size[b] += size[a];
        else
            parent[b] = a, size[a] += size[b];
    }
    bool same_set(ll a, ll b) { return find(a) == find(b); }
    ll get_size(ll x) { return size[find(x)]; }
};
void click_clack_boom() {
    ll n, m, r;
    cin >> n >> m, r = sqrt(n);
    vector<array<ll, 2>> va(m);
    map<ll, ll> deg, rev;
    DSU ds1(n), ds2(n);
    fro(i, 0, m - 1) {
        ll x, y;
        cin >> x >> y, x--, y--;
        va[i] = {x, y};
        deg[x]++, deg[y]++;
        ds1.unite(x, y);
    }
    for (auto [x, y] : deg) rev[y]++;
    if (r * r != n || r * (r + 1) != m || ds1.get_size(0) != n || rev[4] != r || rev[2] != n - r) {
        pr("NO");
        return;
    }
    fro(i, 0, m - 1) {
        auto [x, y] = va[i];
        if (deg[x] != 4 || deg[y] != 4) ds2.unite(x, y);
    }
    set<ll> par;
    fro(i, 0, n - 1) par.insert(ds2.find(i));
    for (auto p : par)
        if (ds2.get_size(p) != r) {
            pr("NO");
            return;
        }
    pr("YES");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    ll too_much_work = 1, copied_work = 1;
    cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--) click_clack_boom();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    // cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}