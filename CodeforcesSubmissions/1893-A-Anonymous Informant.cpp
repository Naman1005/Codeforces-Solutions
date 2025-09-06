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
    ll n, k, i;
    cin >> n >> k;
    i = n - 1;
    vll arr(n);
    vector<bool> vis(n, false);
    fro(_, 0, n - 1) cin >> arr[_];
    while (k--)
    {
        if (arr[i] > n)
        {
            cout << "No\n";
            return;
        }
        if (vis[i])
        {
            cout << "Yes\n";
            return;
        }
        vis[i] = true;
        i -= arr[i];
        if (i < 0)
            i += n;
    }
    cout << "Yes\n";
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