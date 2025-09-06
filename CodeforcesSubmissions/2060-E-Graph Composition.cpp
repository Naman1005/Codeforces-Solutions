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
class DSU
{
    vll parent, size;
 public:
    DSU(ll n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (ll i = 0; i < n; i++)
            parent[i] = i;
    }
    ll find(ll i)
    {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }
    void unite(ll a, ll b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            parent[a] = b, size[b] += size[a];
        else
            parent[b] = a, size[a] += size[b];
    }
    bool same_set(ll a, ll b) { return find(a) == find(b); }
    ll get_size(ll x) { return size[find(x)]; }
};
void click_clack_boom()
{
    ll n, m1, m2, ans = 0;
    ip(n, m1, m2);
    vector<pair<ll, ll>> F(m1), G(m2), temp;
    ip(F, G);
    DSU DG(n + 1), DF(n + 1);
    for (auto [x, y] : G)
        DG.unite(x, y);
    for (auto [x, y] : F)
    {
        if (DG.find(x) == DG.find(y))
            temp.push_back({x, y});
        else
            ans++;
    }
    for (auto [x, y] : temp)
        DF.unite(x, y);
    set<ll> sf, sg;
    fro(i, 1, n) sf.insert(DF.find(i)), sg.insert(DG.find(i));
    ans += sf.size() - sg.size();
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // inp_out();
    cout << setprecision(20) << fixed;
    ll too_much_work = 1;
    cin >> too_much_work;
    while (too_much_work--)
        click_clack_boom();
}