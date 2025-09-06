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
bool check(const vector<vll> &adj, const vll &deg, ll d1, ll d2)
{
    vll temp_deg = deg;
    temp_deg[d1] = 0;
    for (auto v : adj[d1])
        temp_deg[v]--;
    ll mx1 = 0, mx2 = 0;
    for (auto d : temp_deg)
        mx1 = max(mx1, d);
     temp_deg = deg;
    temp_deg[d2] = 0;
    for (auto v : adj[d2])
        temp_deg[v]--;
    for (auto d : temp_deg)
        mx2 = max(mx2, d);
    return mx1 >= mx2;
}
void click_clack_boom()
{
    ll n, u, v, d2 = 0;
    ip(n);
    vll deg(n + 1, 0);
    vector<vll> adj(n + 1);
    fro(i, 1, n - 1)
    {
        ip(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    auto remove = [&](ll v)
    {
        deg[v] = 0;
        for (auto x : adj[v])
            deg[x]--;
    };
    priority_queue<pair<ll, ll>> pq;
    fro(i, 1, n) pq.push({deg[i], i});
     auto [d1, mdn1] = pq.top();
    pq.pop();
    if (pq.top().first == d1 && !check(adj, deg, mdn1, pq.top().second))
    {
        auto temp = pq.top();
        pq.pop();
        pq.push({d1, mdn1});
        d1 = temp.first, mdn1 = temp.second;
    }
    remove(mdn1);
    for (auto d : deg)
        d2 = max(d2, d);
    cout << d1 + d2 - 1 << "\n";
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