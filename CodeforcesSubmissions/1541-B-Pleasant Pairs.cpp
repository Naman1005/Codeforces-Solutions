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
    ll t, n, x, mp, ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pair<ll, ll>> vec;
        fro(i, 0, n - 1)
        {
            cin >> x;
            vec.push_back({x, i + 1});
        }
        sortv(vec);
        ans = 0;
        fro(i, 0, n - 1) fro(j, i + 1, n - 1)
        {
            if (vec[i].first * vec[j].first == vec[i].second + vec[j].second)
                ans++;
            else if (vec[i].first * vec[j].first > 2 * n)
                break;
        }
        cout << ans << "\n";
    }
}