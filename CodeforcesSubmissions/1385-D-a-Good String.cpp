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
vector<vll> cnt;
string s;
ll check(ll l, ll r, char c)
{
    if (r - l == 1)
        return s[l] != c;
    ll mid = (l + r) / 2;
    return min((r - l) / 2 - (cnt[c - 'a'][mid - 1] - (l ? cnt[c - 'a'][l - 1] : 0)) + check(mid, r, c + 1), (r - l) / 2 - (cnt[c - 'a'][r - 1] - (mid ? cnt[c - 'a'][mid - 1] : 0)) + check(l, mid, c + 1));
}
void solve()
{
    ll n;
    cin >> n >> s;
    cnt.clear();
    cnt.resize(26, vll(n, 0));
    fro(i, 0, n - 1) fro(j, 0, 25) cnt[j][i] = (i ? cnt[j][i - 1] : 0) + (s[i] == j + 'a');
    cout << check(0, n, 'a') << '\n';
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