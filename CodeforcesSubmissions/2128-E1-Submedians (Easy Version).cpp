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
void click_clack_boom() {
    ll n, k;
    ip(n, k);
    vll a(n);
    ip(a);
    auto fun = [&](ll v) -> array<ll, 3> {
        vll prf(n + 1), mv{(ll)4e18, (ll)4e18}, mi{-1, -1};
        fro(i, 1, n) prf[i] = prf[i - 1] + (a[i - 1] >= v ? 1 : -1);
        fro(i, 1, n) {
            if ((i - k >= 0) && (prf[i - k] < mv[(i - k) & 1])) mv[(i - k) & 1] = prf[i - k], mi[(i - k) & 1] = i - k;
            if (mi[i & 1] != -1 && prf[i] - mv[i & 1] >= 0) return {1, mi[i & 1] + 1, i};
            if (mi[(i & 1) ^ 1] != -1 && prf[i] - mv[(i & 1) ^ 1] >= 1) return {1, mi[(i & 1) ^ 1] + 1, i};
        }
        return {0, -1, -1};
    };
    ll ans = 1, al = 1, ar = k, lo = 1, hi = n, mid;
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        auto [f, l, r] = fun(mid);
        f ? ans = mid, al = l, ar = r, lo = mid + 1 : hi = mid - 1;
    }
    pr(ans, al, ar, "");
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