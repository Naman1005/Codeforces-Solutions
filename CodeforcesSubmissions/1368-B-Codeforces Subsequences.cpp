#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979323846
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
    vll freq(10, 1);
    string s = "codeforces";
    ll k, c = 1;
    cin >> k;
    while (c < k)
    {
        fro(v, 2, 40)
        {
            fro(i, 0, 9)
            {
                c /= v - 1;
                c *= v;
                freq[i]++;
                if (c >= k)
                    break;
            }
            if (c >= k)
                break;
        }
    }
    fro(i, 0, 9) while (freq[i]--) cout << s[i];
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
}