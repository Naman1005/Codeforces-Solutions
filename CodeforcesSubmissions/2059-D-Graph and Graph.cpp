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
    if constexpr (is_same<T, string>::value || is_same_v<decay_t<T>, const char *> || is_same_v<decay_t<T>, char *>)
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
    ll n, s1, s2, m1, m2;
    ip(n, s1, s2, m1);
    set<pair<ll, ll>> g1;
    vector<bool> safe(n + 1, 0);
    vector<vll> adj1(n + 1), adj2(n + 1);
    fro(i, 1, m1)
    {
        ll u, v;
        ip(u, v);
        if (v < u)
            swap(u, v);
        g1.insert({u, v});
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    ip(m2);
    fro(i, 1, m2)
    {
        ll u, v;
        ip(u, v);
        if (v < u)
            swap(u, v);
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        if (g1.find({u, v}) != g1.end())
            safe[u] = safe[v] = 1;
    }
    vector<vll> dist(n + 1, vll(n + 1, LONG_LONG_MAX));
    dist[s1][s2] = 0;
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    pq.push({0, s1, s2});
    while (!pq.empty())
    {
        auto [d, u1, u2] = pq.top();
        pq.pop();
        if (d > dist[u1][u2])
            continue;
        for (auto v1 : adj1[u1])
            for (auto v2 : adj2[u2])
                if (dist[v1][v2] > d + abs(v1 - v2))
                {
                    dist[v1][v2] = d + abs(v1 - v2);
                    pq.push({dist[v1][v2], v1, v2});
                }
    }
    // pr(dist);
    ll ans = LONG_LONG_MAX;
    fro(i, 1, n) if (safe[i] && dist[i][i] != LONG_LONG_MAX)
        ans = min(ans, dist[i][i]);
    cout << (ans == LONG_LONG_MAX ? -1 : ans) << '\n';
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