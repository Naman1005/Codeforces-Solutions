#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
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
class SegmentTree {
    ll n;
    vll t;
    void build(ll tl, ll tr, ll v, bool op, vll &a) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            ll tm = (tl + tr) >> 1;
            build(tl, tm, v * 2, !op, a);
            build(tm + 1, tr, v * 2 + 1, !op, a);
            if (op)
                t[v] = (t[v * 2] | t[v * 2 + 1]);
            else
                t[v] = (t[v * 2] ^ t[v * 2 + 1]);
        }
    }
    void update_val(ll tl, ll tr, ll v, ll pos, ll new_val, bool op) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            ll tm = (tl + tr) >> 1;
            if (pos <= tm)
                update_val(tl, tm, v * 2, pos, new_val, !op);
            else
                update_val(tm + 1, tr, v * 2 + 1, pos, new_val, !op);
            if (op)
                t[v] = (t[v * 2] | t[v * 2 + 1]);
            else
                t[v] = (t[v * 2] ^ t[v * 2 + 1]);
        }
    }
 public:
    SegmentTree(vll &a) {
        n = a.size();
        t.clear();
        t.resize(n * 4);
        build(0, n - 1, 1, ((ll)log2(n) & 1), a);
    }
    void update(ll p, ll b) { update_val(0, n - 1, 1, p, b, ((ll)log2(n) & 1)); }
    ll get() { return t[1]; }
};
void click_clack_boom() {
    ll n, m, p, b;
    cin >> n >> m;
    n = 1 << n;
    vll a(n);
    ip(a);
    SegmentTree st(a);
    while (m--) {
        cin >> p >> b;
        st.update(p - 1, b);
        cout << st.get() << "\n";
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