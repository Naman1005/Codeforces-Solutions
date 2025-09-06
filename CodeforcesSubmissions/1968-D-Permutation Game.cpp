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
ll get(ll i, ll k, const vll &perm, const vll &arr)
{
    ll x = i, mx = 0, sum = 0;
    vector<bool> vis(perm.size(), false);
    while (!vis[x] && k > 0)
    {
        mx = max(mx, sum + k * arr[x]);
        sum += arr[x];
        vis[x] = true;
        x = perm[x];
        k--;
    }
    return mx;
}
void solve()
{
    ll n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    vll perm(n + 1), arr(n + 1);
    fro(i, 1, n) cin >> perm[i];
    fro(i, 1, n) cin >> arr[i];
    ll b = get(pb, k, perm, arr), s = get(ps, k, perm, arr);
    if (b > s)
        cout << "Bodya\n";
    else if (s > b)
        cout << "Sasha\n";
    else
        cout << "Draw\n";
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