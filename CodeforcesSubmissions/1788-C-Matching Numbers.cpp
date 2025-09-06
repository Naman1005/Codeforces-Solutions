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
#define fro(i, x, y) for (ll i = (x); i <= (y); i++)
#define pre(i, x, y) for (ll i = (x); i >= (y); i--)
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
    ll t, n, c;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (!(n & 1))
        {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        c = 1;
        for (ll i = 2 * n + 1; i >= 3 * (n + 1) / 2; i--, c++)
            cout << c << " " << i - c << "\n";
        for (ll i = (5 * n + 1) / 2; i >= 2 * n + 2; i--, c++)
            cout << c << " " << i - c << "\n";
    }
}