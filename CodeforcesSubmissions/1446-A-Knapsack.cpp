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
void solve()
{
    ll n, w, sum = 0;
    cin >> n >> w;
    vll arr(n), sahi_hai;
    fro(i, 0, n - 1) cin >> arr[i];
    fro(i, 0, n - 1) if (arr[i] <= w)
    {
        if (2 * arr[i] >= w)
        {
            cout << "1\n"
                 << i + 1 << "\n";
            return;
        }
        sum += arr[i];
        sahi_hai.push_back(i + 1);
        if (sum * 2 >= w)
        {
            cout << sahi_hai.size() << "\n";
            for (auto x : sahi_hai)
                cout << x << " ";
            return;
        }
    }
    cout << "-1\n";
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