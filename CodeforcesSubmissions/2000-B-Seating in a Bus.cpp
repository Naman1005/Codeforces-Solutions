#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
    ll n, left = -1, right = -1;
    cin >> n;
    vll arr(n);
    fro(i, 0, n - 1) cin >> arr[i];
    right = arr[0] == n ? -1 : arr[0] + 1, left = arr[0] == 1 ? -1 : arr[0] - 1;
    fro(i, 1, n - 1)
    {
        if (arr[i] == left)
        {
            left = arr[i] == 1 ? -1 : arr[i] - 1;
            continue;
        }
        if (arr[i] == right)
        {
            right = arr[i] == n ? -1 : arr[i] + 1;
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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