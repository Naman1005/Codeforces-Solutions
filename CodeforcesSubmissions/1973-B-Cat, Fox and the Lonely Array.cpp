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
void add_bits(ll n, vll &bits)
{
    for (ll i = 0; n > 0; i++, n >>= 1)
        if (n & 1)
            bits[i]++;
}
void remove_bits(ll n, vll &bits)
{
    for (ll i = 0; n > 0; i++, n >>= 1)
        if (n & 1)
            bits[i]--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll t, n, x, len;
    bool all;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vll vec(n), target_bits(20, 0), curr_bits(20);
        fro(i, 0, n - 1)
        {
            cin >> vec[i];
            add_bits(vec[i], target_bits);
        }
        len = 1, all = false;
        fro(i, 0, n - 1)
        {
            add_bits(vec[i], curr_bits), all = true;
            fro(i, 0, 19) if (target_bits[i] && (!curr_bits[i])) all = false;
            if (all)
                remove_bits(vec[i - len + 1], curr_bits);
            else
                len++;
        }
        cout << len << "\n";
    }
}