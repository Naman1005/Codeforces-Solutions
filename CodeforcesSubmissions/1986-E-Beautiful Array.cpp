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
    ll n, k, ans, odd, len, temp;
    cin >> n >> k;
    vll vec(n);
    map<ll, vll> m;
    fro(i, 0, n - 1)
    {
        cin >> vec[i];
        m[vec[i] % k].push_back(vec[i]);
    }
    ans = 0, odd = 0;
    for (auto x : m)
    {
        sortv(x.second);
        odd += x.second.size() & 1;
        if (odd > 1)
        {
            cout << -1 << endl;
            return;
        }
        if (x.second.size() & 1)
        {
            len = x.second.size() / 2;
            vll prefix(len + 1, 0), suffix(len + 1, 0);
            fro(i, 0, len - 1) prefix[i] = (i ? prefix[i - 1] : 0) + (x.second[2 * i + 1] - x.second[2 * i]) / k;
            pre(i, len - 1, 0) suffix[i] = (i == len - 1 ? 0 : suffix[i + 1]) + (x.second[2 * i + 2] - x.second[2 * i + 1]) / k;
            temp = suffix[0];
            fro(i, 0, len - 1) temp = min(temp, prefix[i] + suffix[i + 1]);
            ans += temp;
        }
        else
            for (ll i = 0; i < x.second.size() - 1; i += 2)
                ans += (x.second[i + 1] - x.second[i]) / k;
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t, n, k, ans, odd;
    cin >> t;
    while (t--)
        solve();
    return 0;
}