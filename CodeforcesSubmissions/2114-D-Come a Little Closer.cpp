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
template <typename T> using pqmn = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using pqmx = priority_queue<T>;
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
    ll ans, n, mnx1 = 1e10, mny1 = 1e10, mxx1 = 0, mxy1 = 0;
    ll mnx2 = 1e10, mny2 = 1e10, mxx2 = 0, mxy2 = 0;
    cin >> n;
    vector<array<ll, 2>> pts(n);
    ip(pts);
    for (auto [x, y] : pts) {
        if (x < mnx1)
            mnx2 = mnx1, mnx1 = x;
        else if (x < mnx2)
            mnx2 = x;
        if (x > mxx1)
            mxx2 = mxx1, mxx1 = x;
        else if (x > mxx2)
            mxx2 = x;
        if (y < mny1)
            mny2 = mny1, mny1 = y;
        else if (y < mny2)
            mny2 = y;
        if (y > mxy1)
            mxy2 = mxy1, mxy1 = y;
        else if (y > mxy2)
            mxy2 = y;
    }
    // pr(ans, "**");
    ans = (mxx1 - mnx1 + 1) * (mxy1 - mny1 + 1);
    for (auto [x, y] : pts) {
        ll cx = (x == mxx1 ? mxx2 : mxx1) - (x == mnx1 ? mnx2 : mnx1) + 1,
           cy = (y == mxy1 ? mxy2 : mxy1) - (y == mny1 ? mny2 : mny1) + 1;
        if (cx * cy > n - 1)
            ans = min(ans, cx * cy);
        else
            ans = min({ans, (cx + 1) * cy, cx * (cy + 1)});
    }
    // pr(mnx1, mny1, mxx1, mxy1);
    pr(ans, " ");
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