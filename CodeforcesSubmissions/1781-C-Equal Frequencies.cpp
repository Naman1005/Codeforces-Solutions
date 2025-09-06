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
void click_clack_boom()
{
    ll n;
    string s, t;
    ip(n, s);
    vector<vll> pos(26);
    vector<pair<ll, char>> vp(26);
    fro(i, 0, 25) vp[i] = {0, 'a' + i};
    fro(i, 0, n - 1) vp[s[i] - 'a'].first++, pos[s[i] - 'a'].push_back(i);
    sort(rall(vp));
    // pr(vp);
    ll ans = 1e18;
    fro(m, 1, 26) if (!(n % m))
    {
        ll fr = n / m;
        ll temp = n;
        fro(i, 0, m - 1) temp -= min(fr, vp[i].first);
        // cout<<m<<" "<<temp << endl;
        if (temp < ans)
        {
            string unused = "";
            ans = temp;
            string st(n, ' ');
            fro(i, 0, m - 1)
            {
                fro(j, 0, min(fr, vp[i].first) - 1) st[pos[vp[i].second - 'a'][j]] = vp[i].second;
                if (fr > vp[i].first)
                    unused += string(fr - vp[i].first, vp[i].second);
            }
            for (auto &c : st)
                if (c == ' ')
                    c = unused.back(), unused.pop_back();
            t = st;
        }
    }
    cout << ans << "\n"
         << t << "\n";
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