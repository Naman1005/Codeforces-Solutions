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
    ll n, temp, ans = 0;
    cin >> n;
    vll m(5);
    fro(i, 0, n - 1)
    {
        cin >> temp;
        m[temp]++;
    }
    ans += m[4] + m[3] + ceil(m[2] / 2.0);
    if (m[1] >= m[3])
        m[1] -= (m[3] + (((m[2] & 1) && m[1]) ? (m[1] == 1 ? 1 : 2) : 0)), ans += ceil(m[1] / 4.0);
    cout << ans << endl;
    return 0;
}