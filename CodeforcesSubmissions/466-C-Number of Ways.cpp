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
    ll n, ans = 0, a = 0, b = 0;
    cin >> n;
    vll arr(n), pref(n, 0);
    fro(i, 0, n - 1)
    {
        cin >> arr[i];
        pref[i] = (i ? pref[i - 1] : 0) + arr[i];
    }
    if (pref[n - 1] % 3)
    {
        cout << "0\n";
        return 0;
    }
    fro(i, 0, n - 2)
    {
        if (pref[i] == pref[n - 1] / 3)
            a++;
        if (pref[i] == 2 * pref[n - 1] / 3)
            b++;
    }
    fro(i, 0, n - 2)
    {
        if (pref[i] == 2 * pref[n - 1] / 3)
            b--;
        if (pref[i] == pref[n - 1] / 3)
            ans += b;
    }
    cout << ans << "\n";
}