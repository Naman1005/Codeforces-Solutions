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
#define pll pair<ll, ll>
#define vpl vector<pll>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fro(i, x, y) for (ll i = (ll)(x); i <= (ll)(y); i++)
#define pre(i, x, y) for (ll i = (ll)(x); i >= (ll)(y); i--)
#define fact(n) (ll) tgamma(n + 1)
#define truncMod(a, b) (ll)(a - (b * (floor(a / b))))
#define slice(s, i, j) (((size_t)(i) >= (s).size() || (size_t)(i) > (size_t)(j)) ? string() : (s).substr((size_t)(i), min((size_t)(j), (s).size() - 1) - (size_t)(i) + 1))
template <typename T> using pqmn = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using pqmx = priority_queue<T>;
ll prefXor(ll n) { return (n & 3) == 0 ? n : (n & 3) == 1 ? 1 : (n & 3) == 2 ? n + 1 : 0; }
ll xorRange(ll l, ll r) { return prefXor(r) ^ (l > 0 ? prefXor(l - 1) : 0); }
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
public:
    vll parent, size;
    DSU(ll n) : size(n + 1, 1), parent(n + 1) { iota(all(parent), 0); }
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
    ll n, m;
    ip(n, m);
    vll ans(n);
    DSU ds(n + 1);
    while (m--) {
        ll l, r, x, nxt;
        ip(l, r, x);
        nxt = ds.find(l);
        while (nxt <= r) {
            if (nxt == x) {
                nxt++;
            } else {
                ans[nxt - 1] = x;
                ds.parent[nxt] = nxt + 1;
            }
            nxt = ds.find(nxt);
        }
    }
    pr(ans);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    ll too_much_work = 1, copied_work = 1;
    // cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--) click_clack_boom();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    // cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}