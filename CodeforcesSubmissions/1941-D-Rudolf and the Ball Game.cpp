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
inline ll clock(ll curr, ll dist, ll n)
{
    return curr + dist - ((curr + dist > n) ? n : 0);
}
inline ll counter_clock(ll curr, ll dist, ll n)
{
    return curr - dist + ((curr - dist <= 0) ? n : 0);
}
void solve()
{
    ll n, m, x, dist;
    cin >> n >> m >> x;
    char type;
    vll curr, prev;
    prev.push_back(x);
    while (m--)
    {
        cin >> dist >> type;
        for (auto k : prev)
        {
            if (type != '1')
                curr.push_back(clock(k, dist, n));
            if (type != '0')
                curr.push_back(counter_clock(k, dist, n));
        }
        sort_and_unique(curr);
        prev = curr;
        curr.clear();
    }
    cout << prev.size() << "\n";
    for (auto k : prev)
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
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}