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
template <typename T, typename = void>
struct is_container : false_type
{
};
template <typename T>
struct is_container<T, void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>> : true_type
{
};
template <typename T1, typename T2>
void pr(const pair<T1, T2> &p) { cout << p.first << ' ' << p.second << endl; }
template <typename T>
void pr(const T &element)
{
    if constexpr (is_same<T, string>::value)
        cout << element << endl;
    else if constexpr (is_container<T>::value)
    {
        for (const auto &e : element)
            pr(e);
        cout << endl;
    }
    else
        cout << element << ' ';
}
template <typename T, typename... Args>
void pr(const T &first, const Args &...args)
{
    pr(first);
    pr(args...);
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}
template <typename T>
void ip(T &element)
{
    if constexpr (is_same<T, string>::value)
        cin >> element;
    else if constexpr (is_container<T>::value)
    {
        for (auto &e : element)
            ip(e);
    }
    else
        cin >> element;
}
template <typename T, typename... Args>
void ip(T &first, Args &...args)
{
    ip(first);
    ip(args...);
}
void inp_out()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
ll cost(const vll &a, ll d)
{
    ll n = a.size();
    multiset<ll> ms;
    vll dp(n, 0);
    ms.insert(a[0]);
    dp[0] = a[0];
    fro(i, 1, n - 1)
    {
        if (i - d - 2 >= 0)
            ms.erase(ms.find(dp[i - d - 2]));
        dp[i] = a[i] + *ms.begin();
        ms.insert(dp[i]);
    }
    return dp[n - 1];
}
void click_clack_boom()
{
    ll n, m, k, d, ans = 0, curr;
    ip(n, m, k, d);
    vector<vll> a(n, vll(m));
    ip(a);
    for (auto &v : a)
        for (auto &x : v)
            x++;
    vll c(n);
    fro(i, 0, n - 1) c[i] = cost(a[i], d);
    fro(i, 0, k - 1) ans += c[i];
    curr = ans;
    fro(i, k, n - 1) curr += c[i] - c[i - k], ans = min(curr, ans);
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll too_much_work = 1;
    cin >> too_much_work;
    while (too_much_work--)
        click_clack_boom();
}