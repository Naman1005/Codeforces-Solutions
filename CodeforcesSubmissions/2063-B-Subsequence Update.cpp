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
void click_clack_boom()
{
    ll n, l, r, s1 = 0, s2 = 0;
    ip(n, l, r);
    vll a(n), t1, t2;
    ip(a);
    fro(i, 0, r - 1) t1.push_back(a[i]);
    fro(i, l - 1, n - 1) t2.push_back(a[i]);
    sort(all(t1));
    sort(all(t2));
    fro(i, 0, r - l) s1 += t1[i];
    fro(i, 0, r - l) s2 += t2[i];
    cout << min(s1, s2) << "\n";
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