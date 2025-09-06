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
    ll n, x, y, ans = 0;
    cin >> n;
    priority_queue<ll> pq1, pq2;
    fro(i, 1, n)
    {
        cin >> x;
        pq1.push(x);
    }
    fro(i, 1, n)
    {
        cin >> x;
        pq2.push(x);
    }
    while (!pq1.empty() && !pq2.empty())
    {
        x = pq1.top();
        pq1.pop();
        y = pq2.top();
        pq2.pop();
        if (x == y)
            continue;
        (x > y) ? x = log10(x) + 1 : y = log10(y) + 1;
        pq1.push(x), pq2.push(y);
        ans++;
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
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}