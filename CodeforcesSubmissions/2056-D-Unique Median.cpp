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
void print(const pair<T1, T2> &p) { cout << p.first << ' ' << p.second << endl; }
template <typename T>
void print(const T &element)
{
    if constexpr (is_same<T, string>::value)
        cout << element << endl;
    else if constexpr (is_container<T>::value)
    {
        for (const auto &e : element)
            print(e);
        cout << endl;
    }
    else
        cout << element << ' ';
}
template <typename T, typename... Args>
void print(const T &first, const Args &...args)
{
    print(first);
    print(args...);
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}
template <typename T>
void input(T &element)
{
    if constexpr (is_same<T, string>::value)
        cin >> element;
    else if constexpr (is_container<T>::value)
    {
        for (auto &e : element)
            input(e);
    }
    else
        cin >> element;
}
template <typename T, typename... Args>
void input(T &first, Args &...args)
{
    input(first);
    input(args...);
}
void inp_out()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void solve()
{
    ll n, ans = 0, temp, sum, r;
    input(n);
    vll a(n);
    input(a);
    ans = (n * (n + 1)) / 2;
    fro(x, 1, 9)
    {
        vll b(n);
        fro(i, 0, n - 1) b[i] = (a[i] <= x ? 1 : -1);
        map<ll, vll> pos;
        sum = temp = 0, r = -1;
        pos[0].push_back(-1);
        fro(i, 0, n - 1)
        {
            sum += b[i];
            if (a[i] == x)
                r = i;
            temp += (lower_bound(pos[sum].begin(), pos[sum].end(), r) - pos[sum].begin());
            pos[sum].push_back(i);
        }
        ans -= temp;
    }
    cout << ans << "\n";
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
        solve();
}