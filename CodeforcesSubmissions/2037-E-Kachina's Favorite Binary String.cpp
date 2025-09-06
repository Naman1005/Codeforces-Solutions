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
ll ask(ll l, ll r)
{
    cout << "? " << l << " " << r << '\n';
    ll ans;
    cin >> ans;
    return ans;
}
template <typename T>
void answer(T ele) { cout << "! " << ele << endl; }
void click_clack_boom()
{
    ll n, p = -1, x, y;
    cin >> n;
    fro(i, 1, n - 1)
    {
        x = ask(1, i + 1);
        if (x > 0)
        {
            p = i;
            break;
        }
    }
    if (p == -1)
    {
        answer("IMPOSSIBLE");
        return;
    }
    string ans(n, '1');
    pre(i, p - 1, p - x) ans[i] = '0';
    fro(i, p + 1, n - 1)
    {
        y = ask(1, i + 1);
        (y > x) ? ans[i] = '1' : ans[i] = '0';
        x = y;
    }
    answer(ans);
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
    cerr << "Total: " << (elapsed.count()) << " ms\nAvg:" << (elapsed.count() / (ld)copied_work) << " ms" << endl;
}