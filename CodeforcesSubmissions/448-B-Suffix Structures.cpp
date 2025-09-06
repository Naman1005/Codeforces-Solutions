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
string s, t;
bool check(ll j = 0)
{
    fro(i,0,s.size()-1)
    {
        if(s[i] == t[j])
            j++;
        if(j == t.size())
            break;
    }
    return j == t.size();
}
void solve()
{
    cin >> s >> t;
    if(check())
    {
        cout << "automaton\n";
        return;
    }
    sort(all(s));
    sort(all(t));
    if (s == t)
    {
        cout << "array\n";
        return;
    }
    if(check())
    {
        cout << "both\n";
        return;
    }
    cout << "need tree\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t = 1;
    // cin>>t;
    while (t--)
        solve();
}