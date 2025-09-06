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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll n, m, q, cnt = 0, type, u, v;
    cin >> n >> m;
    vll deg(n + 1, 0), less(n + 1, 0);
    fro(i, 1, m)
    {
        cin >> u >> v;
        deg[u]++, deg[v]++;
        less[v] += u < v, less[u] += v < u;
    }
    fro(i, 1, n) cnt += (less[i] == deg[i]);
    cin >> q;
    while (q--)
    {
        cin >> type;
        switch (type)
        {
        case 1:
            cin >> u >> v;
            cnt -= (less[u] == deg[u]) + (less[v] == deg[v]);
            deg[u]++, deg[v]++;
            less[v] += u < v, less[u] += v < u;
            cnt += (less[u] == deg[u]) + (less[v] == deg[v]);
            break;
        case 2:
            cin >> u >> v;
            cnt -= (less[u] == deg[u]) + (less[v] == deg[v]);
            deg[u]--, deg[v]--;
            less[v] -= u < v, less[u] -= v < u;
            cnt += (less[u] == deg[u]) + (less[v] == deg[v]);
            break;
        case 3:
            cout << cnt << "\n";
            break;
        }
    }
}