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
void solve()
{
    ll l, r, n, s = 0;
    bool f = false;
    cin >> n;
    vll a(n), b(n), c(n), preA(n), preB(n), preC(n);
    fro(i, 0, n - 1)
    {
        cin >> a[i];
        preA[i] = (i == 0 ? 0 : preA[i - 1]) + a[i];
        s += a[i];
    }
    fro(i, 0, n - 1)
    {
        cin >> b[i];
        preB[i] = (i == 0 ? 0 : preB[i - 1]) + b[i];
    }
    fro(i, 0, n - 1)
    {
        cin >> c[i];
        preC[i] = (i == 0 ? 0 : preC[i - 1]) + c[i];
    }
    s = ceil(s / 3.0);
    fro(i, 0, n - 1)
    {
        if (preB[i] < s)
            continue;
        l = upper_bound(all(preB), preB[i] - s) - preB.begin(), r = i;
        if (l > r || l == 0)
            continue;
        if (preA[l - 1] >= s && preC[n - 1] - preC[r] >= s)
        {
            f = true;
            cout << 1 << " " << l << " " << l + 1 << " " << r + 1 << " " << r + 2 << " " << n << "\n";
            return;
        }
        else if (preC[l - 1] >= s && preA[n - 1] - preA[r] >= s)
        {
            f = true;
            cout << r + 2 << " " << n << " " << l + 1 << " " << r + 1 << " " << 1 << " " << l << "\n";
            return;
        }
    }
    fro(i, 0, n - 1)
    {
        if (preC[i] < s)
            continue;
        l = upper_bound(all(preC), preC[i] - s) - preC.begin(), r = i;
        if (l > r || l == 0)
            continue;
        if (preA[l - 1] >= s && preB[n - 1] - preB[r] >= s)
        {
            f = true;
            cout << 1 << " " << l << " " << r + 2 << " " << n << " " << l + 1 << " " << r + 1 << "\n";
            return;
        }
        else if (preB[l - 1] >= s && preA[n - 1] - preA[r] >= s)
        {
            f = true;
            cout << r + 2 << " " << n << " " << 1 << " " << l << " " << l + 1 << " " << r + 1 << "\n";
            return;
        }
    }
    fro(i, 0, n - 1)
    {
        if (preA[i] < s)
            continue;
        l = upper_bound(all(preA), preA[i] - s) - preA.begin(), r = i;
        if (l > r || l == 0)
            continue;
        if (preB[l - 1] >= s && preC[n - 1] - preC[r] >= s)
        {
            f = true;
            cout << l + 1 << " " << r + 1 << " " << 1 << " " << l << " " << r + 2 << " " << n << "\n";
            return;
        }
        else if (preC[l - 1] >= s && preB[n - 1] - preB[r] >= s)
        {
            f = true;
            cout << l + 1 << " " << r + 1 << " " << r + 2 << " " << n << " " << 1 << " " << l << "\n";
            return;
        }
    }
    if (!f)
        cout << "-1\n";
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