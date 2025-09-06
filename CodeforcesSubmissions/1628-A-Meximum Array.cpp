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
 void solve()
{
    ll mx, n, i, j;
    set<ll> s;
    cin >> n;
    vll brr, arr(n), mex_suf(n);
    fro(i, 0, n - 1) cin >> arr[i];
    mx = *max_element(all(arr));
    fro(i, 0, mx + 1) s.insert(i);
    pre(i, n - 1, 0)
    {
        auto it = s.find(arr[i]);
        if (it != s.end())
            s.erase(it);
        mex_suf[i] = *s.begin();
    }
    fro(i, 0, mx + 1) s.insert(i);
    i = j = 0;
    while (i < n)
    {
        set<ll> s2 = s;
        s2.erase(arr[i]);
        j = i + 1;
        while (*s2.begin() != mex_suf[i])
        {
            s2.erase(arr[j]);
            j++;
        }
        brr.push_back(*s2.begin());
        i = j;
    }
     cout << brr.size() << "\n";
    for (auto x : brr)
        cout << x << " ";
    cout << "\n";
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