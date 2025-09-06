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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll zero, one;
    cin >> zero >> one;
    if (zero < (one - 1) / 2 || one < (zero - 1))
    {
        cout << "-1\n";
        return 0;
    }
    if (one <= zero + 1)
    {
        if (one > zero - 1)
            cout << 1;
        fro(i, 1, 2 * zero - 1) cout << "10"[i & 1];
        if (one == zero + 1)
            cout << 1;
        cout << "\n";
        return 0;
    }
    fro(i, 1, 2 * zero + 1)
    {
        if ((i & 1) && ((i + 1) / 2 <= one - zero - 1))
            cout << 1;
        cout << "01"[i & 1];
    }
    cout << "\n";
}