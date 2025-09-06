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
const ll N = 1e7;
ll Div[N + 1];
vll pr;
vll Get(ll n)
{
    vll res;
    while (n != 1)
    {
        if (res.empty() || res.back() != Div[n])
            res.push_back(Div[n]);
        n /= Div[n];
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
     memset(Div, 0, sizeof(Div));
    fro(i, 2, N)
    {
        if (!Div[i])
            Div[i] = i, pr.push_back(i);
        for (ll x : pr)
        {
            if (i * x > N)
                break;
            Div[i * x] = x;
            if (i % x == 0)
                break;
        }
    }
    ll n, x;
    vector<pair<ll, ll>> ans;
    cin >> n;
    while (n--)
    {
        cin >> x;
        vll dv = Get(x);
        if (dv.size() == 1)
            ans.push_back({-1, -1});
        else
        {
            ll temp = 1;
            for (int d : dv)
                temp *= d;
            ans.push_back({dv[0], temp / dv[0]});
        }
    }
    for (auto a : ans)
        cout << a.first << " ";
    cout << "\n";
    for (auto a : ans)
        cout << a.second << " ";
    cout << "\n";
    return 0;
}