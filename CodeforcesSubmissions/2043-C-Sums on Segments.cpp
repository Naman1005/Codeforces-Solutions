#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define all(a) (a).begin(), (a).end()
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
// ll MAXI(const vll &arr, ll l, ll r)
// {
//     ll ans = arr[l], cur = arr[l];
//     fro(i, l + 1, r) cur = max(cur + arr[i], arr[i]), ans = max(ans, cur);
//     return ans;
// }
// ll MINI(const vll &arr, ll l, ll r)
// {
//     ll cur = LONG_LONG_MAX, ans = LONG_LONG_MAX;
//     fro(i, l, r)(cur > 0) ? cur = arr[i] : cur += arr[i], ans = min(ans, cur);
//     return ans;
// }
void click_clack_boom()
{
    ll n, strange = -1, lmn, lmx, rmn, rmx, sum;
    ip(n);
    vll arr(n);
    ip(arr);
    fro(i, 0, n - 1) if (arr[i] != 1 && arr[i] != -1) strange = i;
    set<ll> s;
    s.insert(0);
     auto MINI = [&](ll l, ll r)
    {
        ll cur = LONG_LONG_MAX, ans = LONG_LONG_MAX;
        fro(i, l, r)(cur > 0) ? cur = arr[i] : cur += arr[i], ans = min(ans, cur);
        return ans;
    };
    auto MAXI = [&](ll l, ll r)
    {
        ll ans = arr[l], cur = arr[l];
        fro(i, l + 1, r) cur = max(cur + arr[i], arr[i]), ans = max(ans, cur);
        return ans;
    };
     if (strange == -1)
    {
        lmn = MINI(0, n - 1);
        lmx = MAXI(0, n - 1);
        fro(i, lmn, lmx) s.insert(i);
    }
    else
    {
        lmn = MINI(0, strange - 1), lmx = MAXI(0, strange - 1);
        fro(i, lmn, lmx) s.insert(i);
        rmn = MINI(strange + 1, n - 1), rmx = MAXI(strange + 1, n - 1);
        fro(i, rmn, rmx) s.insert(i);
         sum = lmn = lmx = 0;
        pre(i, strange - 1, 0)
        {
            sum += arr[i];
            lmn = min(lmn, sum);
            lmx = max(lmx, sum);
        }
         sum = rmn = rmx = 0;
        fro(i, strange + 1, n - 1)
        {
            sum += arr[i];
            rmn = min(rmn, sum);
            rmx = max(rmx, sum);
        }
         fro(i, lmn + arr[strange] + rmn, lmx + arr[strange] + rmx) s.insert(i);
    }
     cout << s.size() << "\n";
    pr(s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    cin >> t;
    while (t--)
        click_clack_boom();
}