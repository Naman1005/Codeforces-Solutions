#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define um unordered_map
#define all(a) (a).begin(), (a).end()
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
struct PAIR
{
    ll a, b;
    bool sw;
    PAIR() { sw = false; }
};
bool cmp(const PAIR &A, const PAIR &B) { return make_pair(A.a, A.b) < make_pair(B.a, B.b); }
void solve()
{
    ll n;
    cin >> n;
    vector<PAIR> a(n);
    for (auto &PAIR : a)
    {
        cin >> PAIR.a >> PAIR.b;
        if (PAIR.a > PAIR.b)
        {
            swap(PAIR.a, PAIR.b);
            PAIR.sw = true;
        }
    }
    sort(all(a), cmp);
    for (auto PAIR : a)
        (PAIR.sw) ? cout << PAIR.b << " " << PAIR.a << " " : cout << PAIR.a << " " << PAIR.b << " ";
    cout << '\n';
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