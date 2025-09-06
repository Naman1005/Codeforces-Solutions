#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
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
    ll n, m, x, cnt;
    cin >> n >> m;
    pair<ll, ll> a, b;
    priority_queue<pair<ll, ll>> pq;
    fro(i, 0, n - 1)
    {
        cnt = 0;
        cin >> x;
        while (x % 10 == 0)
            cnt++, x /= 10;
        pq.push({cnt, to_string(x).size() + cnt});
    }
    a = pq.top();
    pq.pop();
    a.second -= a.first;
    a.first = 0;
    pq.push(a);
    while (pq.size() > 1)
    {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        a.first = min(a.first, b.first);
        a.second += b.second;
        pq.push(a);
         a = pq.top();
        pq.pop();
        a.second -= a.first;
        a.first = 0;
        pq.push(a);
    }
    if (pq.top().second <= m)
        cout << "Anna\n";
    else
        cout << "Sasha\n";
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