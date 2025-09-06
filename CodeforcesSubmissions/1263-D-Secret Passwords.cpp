#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
#define fro(i, x, y) for (ll i = (ll)(x); i <= (ll)(y); i++)
#define pre(i, x, y) for (ll i = (ll)(x); i >= (ll)(y); i--)
#define fact(n) (ll) tgamma(n + 1)
#define truncMod(a, b) (ll)(a - (b * (floor(a / b))))
void inp_out()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
#include <vector>
using namespace std;
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
void solve()
{
    ll n;
    string s;
    cin >> n;
    DSU dsu(27);
    vector<bool> vis(27, false);
    while (n--)
    {
        cin >> s;
        fro(i, 0, s.size() - 2)
        {
            vis[s[i] - 'a'] = true;
            dsu.unite(s[i] - 'a', s[i + 1] - 'a');
        }
        vis[s.back() - 'a'] = true;
    }
    set<ll> st;
    fro(i, 0, 26) if (vis[i]) st.insert(dsu.find(i));
    cout << st.size() << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
}