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
    ll t, n, m, a, b;
    bool flag;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vll vec(n + 1, 0);
        while (m--)
        {
            cin >> a >> b;
            vec[a]++, vec[b]++;
        }
        sortv(vec);
        a = vec[n];
        pre(i, n - 1, 0) if (vec[i] == 1)
        {
            b = vec[i + 1];
            break;
        }
        if (vec[n] == vec[n - 1])
            cout << b << " " << a - 1 << "\n";
        else
            cout << a << " " << b - 1 << "\n";
    }
}