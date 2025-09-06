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
    ll n, t, ans, a, b, x;
    bool flag;
    string s, val;
    cin >> t;
    while (t--)
    {
        flag = false;
        cin >> n >> s;
        if (n == 2)
        {
            if (s[0] == '0')
                cout << s[1] << endl;
            else
                cout << s << endl;
            continue;
        }
        fro(i, 0, n - 1) if (s[i] == '0') flag = true;
        ans = 1e18;
        if (flag)
        {
            if (n >= 4)
                cout << 0 << endl;
            else
            {
                if (s[1] == '0')
                {
                    a = s[0] - '0', b = s[2] - '0';
                    ans = min(a + b, a * b);
                    cout << ans << endl;
                }
                else
                    cout << 0 << endl;
            }
            continue;
        }
        fro(i,0,n-2)
        {
            vector<ll> v;
            fro(j,0,n-1)
            {
                if (j == i)
                    val = "", val = val + s[j] + s[j + 1], j++, v.push_back(stoi(val));
                else
                    val = "", val = val + s[j], v.push_back(stoi(val));
            }
            x = v[0];
            if (x == 1) x = 0;
            fro(i,1,v.size()-1)
            {
                if (v[i] == 1) continue;
                x = x + v[i];
            }
            ans = min(ans, x);
        }
        cout << ans << endl;
    }
}