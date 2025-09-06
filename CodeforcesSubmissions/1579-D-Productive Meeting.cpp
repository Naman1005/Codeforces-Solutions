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
#define fro(i, x, y) for (ll i = (ll)(x); i <= (ll)(y); i++)
#define pre(i, x, y) for (ll i = (ll)(x); i >= (ll)(y); i--)
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
    ll n, x;
    cin >> n;
    pair<ll, ll> p1, p2;
    vector<pair<ll, ll>> ans;
    priority_queue<pair<ll, ll>> pq;
    fro(i, 1, n)
    {
        cin >> x;
        if (!x)
            continue;
        pq.push({x, i});
    }
    while (pq.size() > 1)
    {
        p1 = pq.top();
        pq.pop();
        p2 = pq.top();
        pq.pop();
        ans.push_back({p1.second, p2.second});
        p1.first--;
        p2.first--;
        if (p1.first)
            pq.push(p1);
        if (p2.first)
            pq.push(p2);
    }
    cout << ans.size() << "\n";
    for (auto &i : ans)
        cout << i.first << " " << i.second << "\n";
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