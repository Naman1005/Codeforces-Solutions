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
    string s;
    cin >> s;
    ll c2 = 0, c3 = 0, sm = 0;
    for (auto c : s)
        c2 += (c == '2'), c3 += (c == '3'), sm += (c - '0');
    if (sm % 9)
    {
        sm %= 9;
        sm = 9 * (2 - (sm & 1)) - sm;
        ll i = 0;
        while (i <= c2)
        {
            if (2 * i > sm)
                break;
            ll j = 0;
            while (j <= c3)
            {
                if (i * 2 + j * 6 > sm)
                    break;
                if (i * 2 + j * 6 == sm)
                {
                    cout << "YES\n";
                    return;
                }
                j++;
            }
            i++;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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