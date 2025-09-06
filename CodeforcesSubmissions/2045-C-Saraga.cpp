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
const ll MAX = LONG_LONG_MAX;
void solve()
{
    ll mn = MAX, si = -1, ti = -1;
    string s, t;
    cin >> s >> t;
    vll vs(26, MAX);
    fro(i, 1, s.size() - 1) vs[s[i] - 'a'] = min(vs[s[i] - 'a'], i);
    fro(i, 0, t.size() - 2) if (vs[t[i] - 'a'] != MAX && vs[t[i] - 'a'] + t.size() - i < mn)
        mn = vs[t[i] - 'a'] + t.size() - i,
        si = vs[t[i] - 'a'], ti = i;
    if (si == -1)
        cout << "-1\n";
    else
        cout << s.substr(0, si + 1) + t.substr(ti + 1, t.size() - ti) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
}