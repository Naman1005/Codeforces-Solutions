#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.141592653589793238462643383279
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
ll n;
void odd()
{
    ll ans = 0;
    vll arr(n);
    fro(i, 0, n - 1) cin >> arr[i];
    fro(i, 1, n - 2) ans += max(0LL, max(arr[i - 1], arr[i + 1]) + 1 - arr[i++]);
    cout << ans << "\n";
    return;
}
void even()
{
    ll ans = 0;
    vll arr(n), forw, back, cost(n,-1);
    fro(i, 0, n - 1) cin >> arr[i];
    fro(i, 1, n - 2) cost[i] = max(0LL, max(arr[i - 1], arr[i + 1]) + 1 - arr[i]);
    forw.push_back(0);
    fro(i, 1, n - 3) ans += cost[i++], forw.push_back(ans);
    ans = 0;
    pre(i, n - 2, 2) ans += cost[i--], back.push_back(ans);
    reverse(all(back));
    back.push_back(0);
    ans = LONG_LONG_MAX;
    fro(i, 0, forw.size() - 1) ans = min(ans, forw[i] + back[i]);
    cout << ans << "\n";
    return;
}
void solve()
{
    cin >> n;
    if (n & 1)
        odd();
    else
        even();
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