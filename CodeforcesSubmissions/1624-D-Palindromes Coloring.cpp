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
void print_pq(priority_queue<ll, vll, greater<ll>> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}
void solve()
{
    ll n, k, pairs = 0, single = 0, tp;
    priority_queue<ll, vll, greater<ll>> pq, pq2;
    string s;
    map<char, ll> mp;
    cin >> n >> k;
    cin >> s;
    fro(i, 0, n - 1) mp[s[i]]++;
    for (auto &x : mp)
        pairs += 2 * (x.second / 2), single += x.second & 1;
    fro(i, 1, k) pq.push(0);
    while (pairs / 2 >= k)
    {
        fro(i, 1, k) tp = pq.top(), tp += 2, pq.pop(), pq.push(tp);
        pairs -= 2 * k;
    }
    while (!pq.empty() && single)
        pq2.push(pq.top() + 1), single--, pq.pop();
    while (!pq.empty() && pairs)
        pq2.push(pq.top() + 1), pairs--, pq.pop();
    while (!pq.empty())
        pq2.push(pq.top()), pq.pop();
    cout << pq2.top() << endl;
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