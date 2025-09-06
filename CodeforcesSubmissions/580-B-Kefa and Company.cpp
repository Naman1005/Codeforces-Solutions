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
    ll n, d, ms = 0, cs = 0, p = 0;
    cin >> n >> d;
    vector<pair<ll, ll>> vec(n);
    fro(i, 0, n - 1) cin >> vec[i].first >> vec[i].second;
    sortv(vec);
    fro(i, 0, n - 1)
    {
        cs += vec[i].second;
        while (vec[i].first - vec[p].first >= d)
            cs -= vec[p].second, p++;
        ms = max(ms, cs);
    }
    cout << ms << "\n";
    return 0;
}