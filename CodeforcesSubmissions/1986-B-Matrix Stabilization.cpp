#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
#define sortv(v) sort(all(v))
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
ll arr[101][101];
ll check(ll i, ll j, ll n, ll m)
{
    bool up, down, left, right;
    ll mx = -1;
    up = down = left = right = true;
    if (i != 0)
    {
        up = arr[i][j] > arr[i - 1][j];
        mx = max(mx, arr[i - 1][j]);
    }
    if (j != 0)
    {
        left = arr[i][j] > arr[i][j - 1];
        mx = max(mx, arr[i][j - 1]);
    }
    if (i != n - 1)
    {
        down = arr[i][j] > arr[i + 1][j];
        mx = max(mx, arr[i + 1][j]);
    }
    if (j != m - 1)
    {
        right = arr[i][j] > arr[i][j + 1];
        mx = max(mx, arr[i][j + 1]);
    }
    if (up && down && left && right)
        return mx;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t, n, m, mx;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        fro(i, 0, n - 1) fro(j, 0, m - 1) cin >> arr[i][j];
        fro(i, 0, n - 1)
            fro(j, 0, m - 1)
                mx = check(i, j, n, m),
                arr[i][j] = mx ? mx : arr[i][j];
        fro(i, 0, n - 1)
        {
            fro(j, 0, m - 1) cout << arr[i][j] << " ";
            cout << "\n";
        }
    }
}