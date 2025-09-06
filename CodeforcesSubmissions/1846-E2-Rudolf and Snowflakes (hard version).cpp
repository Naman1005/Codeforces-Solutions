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
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    map<ll,bool> mp;
    fro(i, 2, 1e6)
    {
        ll v = 1 + i, p = i * i;
        fro(j, 3, 63)
        {
            v += p;
            if (v > 1e18)
                break;
            mp[v] = true;
            if (p > (ll)(1e18) / i)
                break;
            p *= i;
        }
    }
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        double x = (sqrt(4 * n - 3) - 1) / 2.0;
        if (n < 7)
        {
            cout << "NO\n";
            continue;
        }
        if (x == floor(x) || mp[n])
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}