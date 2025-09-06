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
vll primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
void solve()
{
    ll n, mx = 0;
    cin >> n;
    vll arr(n), used;
    fro(i, 0, n - 1)
    {
        cin >> arr[i];
        fro(j, 0, 10) if (arr[i] % primes[j] == 0)
        {
            used.push_back(primes[j]);
            break;
        }
    }
    sort_and_unique(used);
    cout << used.size() << '\n';
    fro(i, 0, n - 1) fro(j, 0, used.size() - 1) if (arr[i] % used[j] == 0)
    {
        cout << j + 1 << " ";
        break;
    }
    cout << '\n';
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