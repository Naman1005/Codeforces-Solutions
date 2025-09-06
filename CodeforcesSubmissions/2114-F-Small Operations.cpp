#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fro(i, x, y) for (ll i = (ll)(x); i <= (ll)(y); i++)
#define pre(i, x, y) for (ll i = (ll)(x); i >= (ll)(y); i--)
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
vll divisors(ll x) {
    vll div;
    fro(i, 1, sqrt(x)) if (x % i == 0) {
        div.push_back(i);
        if (i != x / i) div.push_back(x / i);
    }
    return div;
}
ll moves(ll x, ll k) {
    vll div = divisors(x);
    sort(all(div));
    vll dp(div.size(), LLONG_MAX);
    dp[0] = 0;
    fro(i, 1, div.size() - 1) {
        fro(j, 0, i - 1) {
            if (div[i] % div[j] == 0 && div[i] / div[j] <= k) dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    return dp.back() == LLONG_MAX ? -1 : dp.back();
}
void click_clack_boom() {
    ll x, y, k, g;
    ip(x, y, k);
    g = __gcd(x, y);
    x /= g, y /= g;
    ll dx = moves(x, k), dy = moves(y, k);
    if (dx < 0 || dy < 0) {
        pr("-1");
        return;
    }
    pr(dx + dy, " ");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    ll too_much_work = 1, copied_work = 1;
    cin >> too_much_work, copied_work = too_much_work;
    while (too_much_work--) click_clack_boom();
}