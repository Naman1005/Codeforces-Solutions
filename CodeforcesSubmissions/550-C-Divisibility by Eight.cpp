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
bool check(string s, string t)
{
    ll i = 0, j = 0, sn = s.length(), tn = t.length();
    while (j < sn)
    {
        if (s[j] == t[i])
            i++;
        if (i == tn)
            break;
        j++;
    }
    if (i == tn)
    {
        cout << "YES\n"
             << t;
        return true;
    }
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inp_out();
    cout << setprecision(20) << fixed;
    string s;
    cin >> s;
    ll i = 8;
    vector<string> vec;
    while (i < 1000)
    {
        vec.push_back(to_string(i));
        i += 8;
    }
    vec.push_back("0");
    fro(i, 0, vec.size() - 1) if (check(s, vec[i])) return 0;
    cout << "NO\n";
}