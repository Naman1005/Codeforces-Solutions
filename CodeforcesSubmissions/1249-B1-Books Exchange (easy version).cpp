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
    ll n;
    cin >> n;
    vll arr(n), ans(n);
    vector<bool> done(n);
    fro(i, 0, n - 1)
    {
        cin >> arr[i];
        arr[i]--;
    }
    fro(i, 0, n - 1) if (!done[i])
    {
        vll c;
        while (!done[i])
            c.push_back(arr[i]), done[i] = true, i = arr[i];
        for (auto k : c)
            ans[k] = c.size();
    }
    for (auto k : ans)
        cout << k << " ";
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t;
    cin >> t;
    while (t--)
        solve();
}