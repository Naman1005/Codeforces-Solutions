#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define fro(i, x, y) for (ll i = x; i <= y; i++)
#define pre(i, x, y) for (ll i = x; i >= y; i--)
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
    string s;
    cin >> s;
    ll n = s.size(), ans;
    if (n < 3)
    {
        cout << "0\n";
        return;
    }
    vector<vll> prefix(n, vll(2));
    fro(i, 0, n - 1) prefix[i][0] = (i ? prefix[i - 1][0] : 0) + (s[i] == '0'), prefix[i][1] = (i ? prefix[i - 1][1] : 0) + (s[i] == '1');
    ans = min(prefix[n - 1][0], prefix[n - 1][1]);
    fro(i, 0, n - 1) ans = min({ans, prefix[i][0] + prefix[n - 1][1] - prefix[i][1], prefix[i][1] + prefix[n - 1][0] - prefix[i][0]});
    cout << ans << "\n";
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