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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll n, k;
    cin >> n >> k;
    priority_queue<ll> pq;
    fro(i, 0, 31) if (n & (1 << i)) pq.push(1 << i);
    if (k < pq.size() || n < k)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    while (k > pq.size())
        pq.push(pq.top()>>1), pq.push(pq.top()>>1), pq.pop();
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}