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
    map<ll, vll> mp;
    ll n, temp, cnt = 0;
    cin >> n;
    fro(i, 1, n)
    {
        cin >> temp;
        if (!mp[temp].size())
            mp[temp] = {1, i, 0};
        else if (mp[temp][0] == 1)
            mp[temp][0]++, mp[temp][2] = i;
        else if (mp[temp][0] != -1)
        {
            if (i - mp[temp][2] != mp[temp][2] - mp[temp][1])
                mp[temp][0] = -1;
            else
                mp[temp][1] = mp[temp][2], mp[temp][2] = i;
        }
    }
    cnt = 0;
    for (auto it : mp)
        if (it.second[0] != -1)
            cnt++;
    cout << cnt << "\n";
    for (auto it : mp)
        if (it.second[0] != -1)
        {
            if (it.second[2])
                cout << it.first << " " << it.second[2] - it.second[1] << "\n";
            else
                cout << it.first << " " << 0 << "\n";
        }
}