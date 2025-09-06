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
    ll n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vll freqA(27, 0), freqB(27, 0);
    fro(i, 0, n - 1) freqA[a[i] - 'a']++, freqB[b[i] - 'a']++;
    fro(i, 0, 25)
    {
        if (freqA[i] < freqB[i] || (freqA[i] - freqB[i]) % k)
        {
            cout << "No\n";
            return;
        }
        freqA[i + 1] += freqA[i] - freqB[i];
    }
    cout << "Yes\n";
    return;
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