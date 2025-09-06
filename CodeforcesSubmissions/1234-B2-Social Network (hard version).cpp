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
    ll n, k, c = 1;
    cin >> n >> k;
    vll final, arr(n);
    map<ll, bool> m;
    fro(i, 0, n - 1) cin >> arr[i];
    m[arr[0]] = true, final.push_back(arr[0]);
    while (c < n && final.size() < k)
        if (!m[arr[c++]])
            final.push_back(arr[c - 1]), m[arr[c - 1]] = true;
    while (c < n)
        if (!m[arr[c++]])
            final.push_back(arr[c - 1]), m[arr[c - 1]] = true, m[final[final.size() - 1 - k]] = false;
    c = final.size() - 1;
    cout << (final.size() >= k ? k : final.size()) << "\n";
    while (k-- && c > -1)
        cout << final[c--] << " ";
}