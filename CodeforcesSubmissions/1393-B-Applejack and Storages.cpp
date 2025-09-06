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
ll n, q, a;
char c;
vll f(1e5 + 1, 0), fof(5, 0);
void add(ll a)
{
    if (f[a] < 4)
    {
        if (f[a])
            fof[f[a]]--;
        f[a]++;
        fof[f[a]]++;
    }
    else
    {
        f[a]++;
        ll r = f[a] % 4;
        if (r)
        {
            fof[r]++;
            if (r - 1)
                fof[r - 1]--;
        }
        else
            fof[3]--, fof[4]++;
    }
}
void remove(ll a)
{
    if (f[a] < 5)
    {
        fof[f[a]]--;
        f[a]--;
        if (f[a])
            fof[f[a]]++;
    }
    else
    {
        ll r = f[a] % 4;
        f[a]--;
        if (r)
        {
            fof[r]--;
            if (r - 1)
                fof[r - 1]++;
        }
        else
            fof[4]--, fof[3]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    cin >> n;
    fro(i, 0, n - 1)
    {
        cin >> q;
        add(q);
    }
    cin >> q;
    while (q--)
    {
        cin >> c >> a;
        (c == '+') ? add(a) : remove(a);
        cout << ((fof[4] && (fof[4] > 1 || fof[2] > 1 || fof[3] > 1 || (fof[2] && fof[3]))) ? "YES\n" : "NO\n");
    }
}