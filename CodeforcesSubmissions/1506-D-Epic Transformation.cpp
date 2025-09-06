#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll n, temp, fr1, fr2, val1, val2;
    priority_queue<pair<ll, ll>> pq;
    cin >> n;
    map<ll, ll> mp;
    fro(i, 0, n - 1)
    {
        cin >> temp;
        mp[temp]++;
    }
    temp = n;
    for (auto k : mp)
        pq.push({k.second, k.first});
    while (pq.size() > 1)
    {
        fr1 = pq.top().first, val1 = pq.top().second, pq.pop();
        fr2 = pq.top().first, val2 = pq.top().second, pq.pop();
        fr1--, fr2--, temp -= 2;
        if (fr1)
            pq.push({fr1, val1});
        if (fr2)
            pq.push({fr2, val2});
    }
    cout << temp << "\n";
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