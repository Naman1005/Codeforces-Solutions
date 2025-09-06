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
ll ask(ll i, ll j, ll k)
{
    cout << "? " << i << " " << j << " " << k << endl;
    cout << flush;
    ll x;
    cin >> x;
    return x;
}
void click_clack_boom()
{
    ll n, p;
    cin >> n;
    vll a = {1, 2, 3};
    while (1)
    {
        p = ask(a[0], a[1], a[2]);
        if (p == 0)
        {
            cout << "! " << a[0] << " " << a[1] << " " << a[2] << endl;
            cout << flush;
            return;
        }
        a[(a[0] & 1) + (a[1] & 1)] = p;
    }
}
int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); inp_out();
    ll too_much_work = 1, copied_work = 1;
    cin >> too_much_work, copied_work = too_much_work;
    auto begin = chrono::high_resolution_clock::now();
    while (too_much_work--)
        click_clack_boom();
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    // cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}