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
void solve()
{
    string s, res;
    ll k, n, fin, left = 0;
    cin >> s >> k;
    n = s.size();
    vector<vll> pos(10);
    fro(i, 0, n - 1) pos[s[i] - '0'].push_back(i);
    fin = n - k;
    fro(i, 0, fin - 1) fro(j, !i, 9) if (!pos[j].empty())
    {
        auto it = lower_bound(all(pos[j]), left);
        if (it != pos[j].end() && *it <= left + k)
        {
            k -= *it - left;
            left = *it + 1;
            res += char(j + '0');
            break;
        }
    }
    cout << res << "\n";
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