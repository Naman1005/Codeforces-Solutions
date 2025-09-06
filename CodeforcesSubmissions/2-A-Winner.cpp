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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    ll ms = -1, n, score;
    cin >> n;
    map<string, ll> m;
    vector<pair<string, ll>> vec;
    string name;
    fro(i, 1, n)
    {
        cin >> name >> score;
        m[name] += score;
        vec.push_back({name, m[name]});
    }
    for (auto k : m)
        ms = max(ms, k.second);
    fro(i, 0, n - 1)
    {
        if (vec[i].second >= ms && m[vec[i].first] == ms)
        {
            cout << vec[i].first;
            return 0;
        }
    }
}