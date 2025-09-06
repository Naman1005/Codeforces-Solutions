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
struct SegTree {
    ll n;
    vector<ll> tree;
    vector<ll> lazy;
    SegTree(const vector<ll> &a) {
        ll sz = a.size();
        n = 1;
        while (n < sz) n <<= 1;
        tree.assign(2 * n, LLONG_MAX);
        lazy.assign(2 * n, 0);
        for (ll i = 0; i < sz; i++) tree[n + i] = a[i];
        for (ll p = n - 1; p > 0; p--) tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
    }
    // apply an increment v to node p, covering some segment
    void apply(ll p, ll v) {
        tree[p] += v;
        lazy[p] += v;
    }
    // push pending updates from p down to its children
    void push(ll p) {
        if (lazy[p] != 0) {
            apply(p << 1, lazy[p]);
            apply(p << 1 | 1, lazy[p]);
            lazy[p] = 0;
        }
    }
    // recusive range‑add on [l, r), node p covers [L, R)
    void update(ll l, ll r, ll v, ll p, ll L, ll R) {
        if (r <= L || R <= l) return;
        if (l <= L && R <= r) {
            apply(p, v);
            return;
        }
        push(p);
        ll M = (L + R) >> 1;
        update(l, r, v, p << 1, L, M);
        update(l, r, v, p << 1 | 1, M, R);
        tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
    }
    // public wrapper: add v on [l, r] inclusive
    void update(ll l, ll r, ll v) { update(l, r + 1, v, 1, 0, n); }
    // recusive query for min on [l, r), node p covers [L, R)
    ll query(ll l, ll r, ll p, ll L, ll R) {
        if (r <= L || R <= l) return LLONG_MAX;
        if (l <= L && R <= r) return tree[p];
        push(p);
        ll M = (L + R) >> 1;
        return min(query(l, r, p << 1, L, M), query(l, r, p << 1 | 1, M, R));
    }
    // public wrapper: query min on [l, r] inclusive
    ll query(ll l, ll r) { return query(l, r + 1, 1, 0, n); }
};
void click_clack_boom() {
    ll n, q;
    ip(n);
    vll a(n);
    ip(a, q);
    cin.ignore();
    SegTree st(a);
    while (q--) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        vll temp;
        ll x;
        while (iss >> x) temp.push_back(x);
        if (temp.size() == 3) {
            ll l = temp[0], r = temp[1], v = temp[2];
            if (l > r)
                st.update(0, r, v), st.update(l, n - 1, v);
            else
                st.update(l, r, v);
        } else {
            ll l = temp[0], r = temp[1];
            if (l > r)
                pr(min(st.query(0, r), st.query(l, n - 1)), "");
            else
                pr(st.query(l, r), "");
        }
    }
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