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
const ll N = 1e9 + 7;
vll v;
void do_it()
{
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    while (v.size() < 1e5 + 1)
        v.push_back((v[v.size() - 1] + v[v.size() - 2]) % N);
    // for(auto x: v)cout<<x<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    do_it();
    string s;
    cin >> s;
    if (count(all(s), 'w') || count(all(s), 'm'))
    {
        cout << "0\n";
        return 0;
    }
    ll ans = 1, n = s.length();
    fro(i, 0, n - 1) if (s[i] == 'u' || s[i] == 'n')
    {
        ll j = i + 1, cnt = 1;
        while (j < n && s[j] == s[i])
            cnt++, j++;
        ans = (ans * v[cnt]) % N, i = j - 1;
    }
    cout << ans << "\n";
}