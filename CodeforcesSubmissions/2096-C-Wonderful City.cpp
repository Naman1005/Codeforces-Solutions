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
template <typename T>
struct is_container<T, void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>> : true_type {};
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
const ll INF = 4e18;
void click_clack_boom() {
    ll n;
    cin >> n;
    vector<vll> h(n, vll(n));
    vll a(n), b(n), mr(n - 1, 7), mc(n - 1, 7);
    ip(h, a, b);
    fro(i, 0, n - 2) fro(j, 0, n - 1) {
        ll d = h[i][j] - h[i + 1][j];
        if (d >= -1 && d <= 1) mr[i] &= ~(1 << (d + 1));
    }
    fro(i, 0, n - 1) fro(j, 0, n - 2) {
        ll d = h[i][j] - h[i][j + 1];
        if (d >= -1 && d <= 1) mc[j] &= ~(1 << (d + 1));
    }
    auto solve = [&](vll &msk, vll &cst) {
        ll m = msk.size() + 1;
        vll v1 = {0, cst[0]}, v2(2);
        fro(i, 0, m - 2) {
            v2[0] = v2[1] = 4e18;
            fro(r, 0, 1) {
                if (v1[r] >= 4e18) continue;
                fro(s, 0, 1) if (msk[i] & (1 << ((s - r) + 1))) v2[s] = min(v2[s], v1[r] + s * cst[i + 1]);
            }
            v1 = v2;
        }
        return min(v1[0], v1[1]);
    };
    ll r = solve(mr, a), c = solve(mc, b);
    pr((r >= 4e18 || c >= 4e18 ? -1 : r + c), " ");
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