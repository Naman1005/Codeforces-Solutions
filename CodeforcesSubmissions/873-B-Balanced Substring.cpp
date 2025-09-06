#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define umllll unordered_map<ll, ll>
#define umsll unordered_map<string, ll>
#define umcll unordered_map<char, ll>
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
    ll n, ans = 0;
    string s;
    cin >> n >> s;
    vll vec(n + 1, 0);
    fro(i, 1, n) vec[i] = vec[i - 1] + (s[i - 1] == '1' ? 1 : -1);
    umllll first, last;
    fro(i, 1, n)(first[vec[i]] == 0) ? first[vec[i]] = i : last[vec[i]] = i;
    for (auto k : first)
        if (k.first)
            ans = max(ans, last[k.first] - k.second);
    ans = max({ans, last[0], first[0]});
    cout << ans << "\n";
}