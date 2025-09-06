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
    ll n, x;
    cin >> n;
    vector<vll> dp(n + 1, vll(3, 1e9));
    dp[0][0] = 0;
    fro(i, 1, n)
    {
        cin >> x;
        dp[i][0] = min({dp[i-1][0] + 1, dp[i-1][1] + 1, dp[i-1][2] + 1});
        if (x & 1)
            dp[i][1] = min({dp[i][1], dp[i-1][2], dp[i-1][0]});
        if (x >> 1)
            dp[i][2] = min({dp[i][2], dp[i-1][1], dp[i-1][0]});
    }
    // fro(i,0,n)
    // {
    //     for(auto k: dp[i])cout<<k<<" ";
    //     cout<<"\n";
    // }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
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