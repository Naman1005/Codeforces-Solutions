#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.141592653589793238462643383279
#define vi vector<int>
#define vll vector<ll>
#define umllll unordered_map<ll, ll>
#define umsll unordered_map<string, ll>
#define umcll unordered_map<char, ll>
#define sortv(v) sort(v.begin(), v.end())
#define all(a) (a).begin(), (a).end()
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define fro(i, x, y) for (ll i = x; i <= y; i++)
#define pre(i, x, y) for (ll i = x; i >= y; i--)
ll truncMod(double a, double b)
{
    return a - (b * (floor(a / b)));
}
ll fact(ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res *= i;
    return res;
}
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
    ll t;
    ld px, py, ax, ay, bx, by, AO, AP, BO, BP, AB;
    cin >> t;
    while (t--)
    {
        cin >> px >> py >> ax >> ay >> bx >> by;
        AO = sqrt(pow(ax, 2) + pow(ay, 2)), AP = sqrt(pow(ax - px, 2) + pow(ay - py, 2));
        BO = sqrt(pow(bx, 2) + pow(by, 2)), BP = sqrt(pow(bx - px, 2) + pow(by - py, 2));
        AB = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
        cout << min({max(AO, AP), max(BO, BP), max({AB / 2.0, AO, BP}), max({AB / 2.0, BO, AP})}) << "\n";
    }
}