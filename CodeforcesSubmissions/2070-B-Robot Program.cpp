#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
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
void click_clack_boom()
{
    ll n, k, x;
    string s;
    cin >> n >> x >> k >> s;
    vll pref(n + 1, 0);
    fro(i, 0, n - 1) pref[i + 1] = pref[i] + (s[i] == 'R' ? 1 : -1);
    auto fun = [&](long long start)
    {
        fro(i, 1, n) if (start + pref[i] == 0) return i;
        return (ll)-1;
    };
    if (x == 0)
    {
        ll temp = fun(0);
        cout << ((temp == -1) ? 0 : (k / temp)) << "\n";
        return;
    }
    ll t1 = fun(x);
    if (t1 == -1 || t1 > k)
    {
        cout << 0 << "\n";
        return;
    }
    ll ans = 1, rem = k - t1, temp = fun(0);
    cout << ((temp == -1) ? ans : (ans + (rem / temp))) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    ll too_much_work = 1, copied_work = 1;
    cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--)
        click_clack_boom();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    // cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}