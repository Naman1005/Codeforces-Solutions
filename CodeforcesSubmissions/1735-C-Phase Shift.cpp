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
    vector<int> parent, size;
 public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b)
    {
        a = find(a), b = find(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    bool same_set(int a, int b) { return find(a) == find(b); }
    int get_size(int x) { return size[find(x)]; }
};
 void solve()
{
    ll n;
    string s, ans;
    cin >> n >> s;
    um<char, char> prev, next;
    DSU dsu(26);
    fro(i, 0, n - 1)
    {
        if (prev[s[i]] != '\0')
        {
            ans += prev[s[i]];
            continue;
        }
        fro(c, 'a', 'z') if (!((next[c]) || (dsu.same_set(s[i] - 'a', c - 'a') && dsu.get_size(s[i] - 'a') < 26)))
        {
            prev[s[i]] = c, next[c] = s[i];
            dsu.unite(s[i] - 'a', c - 'a');
            ans += c;
            break;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}